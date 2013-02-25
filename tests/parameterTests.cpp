#include "tests.hpp"
#include "../SIPL/Exceptions.hpp"
#include "../tsf-config.h"

// Tests for the parameter system

TEST(ParameterTest, GetDefaultParameters) {
	paramList parameters = initParameters(PARAMETERS_DIR);

	EXPECT_FALSE(getParamBool(parameters, "display"));
	EXPECT_EQ("gpu", getParamStr(parameters, "device"));
	EXPECT_EQ(0.05f, getParam(parameters, "gvf-mu"));

	EXPECT_EQ("Display results", parameters.bools["display"].getDescription());
	EXPECT_EQ("Which type of processor to use", parameters.strings["device"].getDescription());
	EXPECT_EQ("Mu regularization constant of GVF", parameters.numerics["gvf-mu"].getDescription());
}

TEST(ParameterTest, SetParameters) {
	paramList parameters = initParameters(PARAMETERS_DIR);

	parameters = setParameter(parameters, "display", "true");
	EXPECT_TRUE(getParamBool(parameters, "display"));
	parameters = setParameter(parameters, "cropping", "lung");
	EXPECT_EQ("lung", getParamStr(parameters, "cropping"));
	parameters = setParameter(parameters, "tdf-high", "0.9");
	EXPECT_EQ(0.9f, getParam(parameters, "tdf-high"));
}

TEST(ParameterTest, NumericParameterValidation) {
	NumericParameter p;
	ASSERT_NO_THROW(p = NumericParameter(0.2, 0.1, 1.0, 0.1, "asd", "asd"));

	EXPECT_THROW(p.set(0.05), SIPL::SIPLException);
	EXPECT_THROW(p.set(1.2), SIPL::SIPLException);
	EXPECT_NO_THROW(p.set(0.4));
}

TEST(ParameterTest, StringParameterValidation) {
	StringParameter p;
	std::vector<std::string> possibilities;
	possibilities.push_back("test");
	possibilities.push_back("moretest");
	possibilities.push_back("evenmoretest");

	ASSERT_NO_THROW(p = StringParameter("test", possibilities, "asd", "asd"));

	EXPECT_THROW(p.set("abc"), SIPL::SIPLException);
}

TEST(ParameterTest, Description) {
	BoolParameter p(true, "test description", "asd");
	EXPECT_EQ("test description", p.getDescription());

	NumericParameter p2(0.1, 0.1, 0.2, 0.1, "test description", "asd");
	EXPECT_EQ("test description", p2.getDescription());

	std::vector<std::string> possibilities;
	StringParameter p3("asd", possibilities, "test description", "asd");
	EXPECT_EQ("test description", p3.getDescription());
}
