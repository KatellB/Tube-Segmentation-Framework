Tube Segmentation Framework
===================================

The tube segmentation framework is a software for fast segmentation and centerline extraction of tubular structures (e.g. blood vessels and airways) from different modalities (e.g. CT, MR and US) and organs using GPUs and OpenCL.

For details about the implementation see the following publication:   
[GPU accelerated segmentation and centerline extraction of tubular structures in medical images](http://link.springer.com/article/10.1007%2Fs11548-013-0956-x)   
Erik Smistad, Anne C. Elster and Frank Lindseth   
International Journal of Computer Assisted Radiology and Surgery   
2013   

If you use this software in any publications, please cite our article.

See the file LICENSE for license information.

Dependencies
----------------------------------

* OpenCL. You need an OpenCL implementation installed on your system to use this software (AMD, NVIDIA, Intel or Apple)
* Boost iostreams. E.g. on Ubuntu linux use the following package: libboost-iostreams-dev
* The two submodules: SIPL and OpenCLUtilities
* GTK 2 for visualization (not required, used by the SIPL module). On Ubuntu linux use the following package: libgtk2.0-dev

Compiling
----------------------------------

To compile the software first make sure that all software dependencies are installed and set up correctly.
Next, use cmake.

For instance on linux, do the following:
```bash
cmake .
make -j8
```

Usage
----------------------------------

To see the help message use the software with no arguments.
`./tubeSegmentation`

The first arguments is the dataset to process. This has to be a metadata (.mhd) file.

Some test data is available with the software. You can test the program with the following command:
```bash
./tubeSegmentation tests/data/synthetic/dataset_1/noisy.mhd --parameters Synthetic-Vascusynth --display


./tubeSegmentation /data/CLUST/3D/EMC-04/Data/mhdIso/double/007FilterDPAD4Norm.mhd --parameters Neuro-Vessels-USA --display
./tubeSegmentation /data/CLUST/3D/EMC-04/Data/mhd/007Alpha.mhd --parameters Neuro-Vessels-USA --display
./tubeSegmentation /data/CLUST/3D/EMC-04/Data/mhd/007AlphaMedian.mhd --parameters Neuro-Vessels-USA
```


Parameters
----------------------------------

This software has a lot of parameters and several parameter presets are available:
* Lung-Airways-CT
* Neuro-Vessels-USA
* Neuro-Vessels-MRA
* AAA-Vessels-CT
* Liver-Vessels-CT
* Synthetic-Vascusynth

The parameter preset is set with the program argument "--parameters <name>".

Tests
----------------------------------

This software contains several tests written with Google Test.
Install Google Test and run cmake again to compile the tests.
Run the tests using the command `./tests/runTests`



