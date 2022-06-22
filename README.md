# ATLAS Italia Statistics Tutorial 2022

## Authors
Valerio Ippolito - INFN Sezione di Roma
Michele Pinamonti - INFN Sezione di Trieste

## Scope
We will go through the typical steps of defining, filling up and analysing a workspace.

## Preliminaries
### Setup
On lxplus:
```
setupATLAS
lsetup git
lsetup "root 6.20.06-x86_64-centos7-gcc8-opt"
lsetup cmake
cd CommonStatTools
mkdir build
cd build 
cmake ..
make
cd ..
```

On a different cluster:
```
export ATLAS_LOCAL_ROOT_BASE=/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase
source ${ATLAS_LOCAL_ROOT_BASE}/user/atlasLocalSetup.sh
lsetup git
localSetupPython --pythonVersion=3.7.4-x86_64-centos7
lsetup "root 6.20.06-x86_64-centos7-gcc8-opt"
lsetup cmake
cd CommonStatTools
mkdir build
cd build 
cmake ..
make
cd ..
```

### Check-out 
```
git clone --recurse-submodules ssh://git@gitlab.cern.ch:7999/vippolit/statistics-tutorial.git
```

### SWAN cluster
The easiest way to run notebooks is [SWAN](http://swan.cern.ch), a sort of Google Colab provided by CERN which enables access to EOS and other nice stuff:

 1. go on http://cernbox.cern.ch and make sure you have a personal EOS folder
 
 2. it's wise to create a configuration script which is run any time you create a SWAN instance - this is used for example to make sure you can install in a known location all additional python packages; to do so, from lxplus, visit `/eos/user/y/yourusername` (i.e. your CERNBox folder), and run
```
mkdir SWAN_projects
cd SWAN_projects
touch config.sh
```
       
 3. edit the file so that it shows something like
 ```
 #!/bin/bash

 export PYTHONPATH=$CERNBOX_HOME/.local/lib/python3.9/site-packages:$PYTHONPATH
 ```
 (the variable `$CERNBOX_HOME` is defined automatically by SWAN when running)
 
 4. then go on http://swan.cern.ch
 
 5. configure an environment with the software stack 101, CentOS7 (gcc8) as platform, 2 cores, 8 GB of memory and no spark cluster; make sure you specify the environment script you created, i.e.
 ```
 $CERNBOX_HOME/SWAN_projects/config.sh
 ```
 
 6. either from lxplus or from a SWAN terminal window (which you can open clicking on the `>_` icon on the top right of the webpage), go to the `$CERNBOX_HOME/SWAN_projects` directory and checkout this code via
 ```
 git clone --recurse-submodules ssh://git@gitlab.cern.ch:7999/vippolit/statistics-tutorial.git
 ```
 (you might get an error concerning permissions for the file `/eos/user/y/yourusername/.ssh/id_rsa`, and in this case you will need to fix the permissions, e.g. `chmod go-rw /eos/user/y/yourusername/.ssh/id_rsa`)
 
 7. simply double-click on any notebook to open it; cell execution is performed with SHIFT+ENTER (but please do visit https://swan.web.cern.ch/swan/ for more info)


## Structure
We will follow these steps:
 - [X] Create a mock-up workspace with pyROOT+HistFactory
 - [X] Visualize the content of the workspace with ROOT
 - [X] Visualize the content of the workspace with CommonStatTools
 - [X] Compare two workspaces with CommonStatTools
 - [X] Print pre- and post-fit yield tables with CommonStatTools
 - [X] Calculate limits using asymptotic formulae
 - [ ] Calculate limits using toys
 - [X] Calculate local p0 using asymptotic formulae
 - [ ] Calculate local p0 using toys
 - [X] Calculate global p0
 - [ ] Run fit cross-checks
 - [X] Look at fit covariance matrices
 - [X] Rank nuisance parameters (Michele)
 - [ ] Grouped impact table (Michele)
 - [X] Evaluate impact of nuisance parameters over the background yield in a signal region


