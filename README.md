# ATLAS Italia Statistics Tutorial 2022

## Authors

Michele Pinamonti - INFN Sezione di Trieste

*credits to Valerio Ippolito - INFN Sezione di Roma*

## Scope
We will go through the typical steps of defining, filling up and analysing a workspace.

## Preliminaries

[![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/pinamont/statistics-tutorial/HEAD)

.. image:: https://mybinder.org/badge_logo.svg
 :target: https://mybinder.org/v2/gh/pinamont/statistics-tutorial/HEAD
 
### Run on Binder
The easiest way to run notebooks is via [Binder](https://mybinder.org/):

 1. go to https://mybinder.org/v2/gh/pinamont/statistics-tutorial/HEAD ;

 2. have fun;
 


<!--The easiest way to run notebooks is [SWAN](http://swan.cern.ch), a sort of Google Colab provided by CERN which enables access to EOS and other nice stuff:

 1. go on http://cernbox.cern.ch and make sure you have a personal EOS folder
 
 2. it's wise to create a configuration script which is run any time you create a SWAN instance - this is used for example to make sure you can install in a known location all additional python packages; to do so, from lxplus, visit `/eos/user/y/yourusername` (i.e. your CERNBox folder), and run
```
mkdir SWAN_projects
cd SWAN_projects
touch config.sh
```-->
       
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


### Step by step

1. Create a workspace from existing histograms and inspect it:
    - directory `create_data`
    - [create_workspace_minimal.ipynb](create_data/create_workspace_minimal.ipynb): very simple example of workspace creation
    - [create_workspace.ipynb](create_data/create_workspace.ipynb): actual exercise we perform to create the workspace needed for the next steps
    - [inspect_workspace.ipynb](create_data/inspect_workspace.ipynb): workspace inspection, visualization of stored histograms, comparison of workspaces
1. Perform fits and understand results:
    - directory `fit`
    - [simple_fit.ipynb](fit/simple_fit.ipynb): how to perform a fit and how to get fit results
    - [covmatrix.ipynb](fit/covmatrix.ipynb): visualization of correlation matrix of the fitted parameters
    - [postfit_plots.ipynb](fit/postfit_plots.ipynb): very simple visualization of post-fit distributions from workspace
    - [yield_tables.ipynb](fit/yield_tables.ipynb): more elaborate inspection of effect of fit results, creating yield tables
1. Quantify the effect of the systematics on a measurement:
    - directory `systematics`
    - [ranking.ipynb](systematics/ranking.ipynb)
    - [impact_table.ipynb](systematics/impact_table.ipynb)
1. Exclusion limit extraction:
    - directory `limit`
    - [asymptotics.ipynb](limit/asymptotics.ipynb): profile-likelihood ratio limits with asymptotic formulae
    - [toys.ipynb](limit/toys.ipynb): setting limits with toys (or asymptotics) for profile-likelihood and other test statistics
1. Quantification of signal significance:
    - directory `p_values`
    - [pvalues.ipynb](p_values/pvalues.ipynb)

 
