# ATLAS Italia Statistics Tutorial 2022

## Authors
Valerio Ippolito - INFN Sezione di Roma

## Scope
We will go through the typical steps of defining, filling up and analysing a workspace.

## Installation
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
```

### Check-out 
```
git clone --recurse-submodules ssh://git@gitlab.cern.ch:7999/vippolit/statistics-tutorial.git
```

## Structure
We will follow these steps:
 - [X] Create a mock-up workspace with pyROOT+HistFactory
 - [ ] Create a mock-up workspace with pyhf
 - [X] Visualize the content of the workspace with ROOT
 - [X] Visualize the content of the workspace with CommonStatTools
 - [X] Compare two workspaces with CommonStatTools
 - [ ] Print pre- and post-fit yield tables with CommonStatTools
 - [ ] Calculate limits using asymptotic formulae
 - [ ] Calculate limits using toys
 - [ ] Calculate local p0 using asymptotic formulae
 - [ ] Calculate local p0 using toys
 - [ ] Calculate global p0
 - [ ] Run fit cross-checks
 - [ ] Look at fit covariance matrices
 - [ ] Rank nuisance parameters
 - [ ] Evaluate impact of nuisance parameters over the background yield in a signal region


