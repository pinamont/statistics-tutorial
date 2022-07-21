# Statistics Tutorial - ICTP ATLAS Open Data 2022

## Authors

Michele Pinamonti - INFN Sezione di Trieste

*credits to: Valerio Ippolito - INFN Sezione di Roma*

## Scope
We will go through the typical steps of defining, filling up and analysing a workspace.

## Preliminaries

[![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/pinamont/statistics-tutorial/HEAD)
 
### Run on Binder

There are two main ways to run this tutorial:

 1. via [Swan](https://swan.web.cern.ch/swan/) - CERN account needed:
 
    1. go to http://cernbox.cern.ch and make sure you have a personal EOS folder;
    
    1. in cernbox, go to `SWAN_projetcs` (single click from the web-browser interface) and create a new text file, with this content:
    
            #!/bin/bash
            export PYTHONPATH=$CERNBOX_HOME/.local/lib/python3.9/site-packages:$PYTHONPATH
    
    1. go to https://swan-k8s.cern.ch/hub/spawn;
    
    1. configure an environment with the software stack 101, CentOS7 (gcc8) as platform, 2 cores, 8 GB of memory and no spark cluster; make sure you specify the environment script you created, i.e. `$CERNBOX_HOME/SWAN_projects/config.sh`
    
    1. create a new project (clicking on the `+` at the bottom right, "Add new projetc"), and call it `statistics-tutorial-ICTP`;
    
    1. from a SWAN terminal window (which you can open clicking on the `>_` icon on the top right of the webpage), go to the `$CERNBOX_HOME/SWAN_projects/statistics-tutorial-ICTP` directory and checkout the repository with:
    
            git clone git@github.com:pinamont/statistics-tutorial.git
            
        or
            
            git clone https://github.com/pinamont/statistics-tutorial.git
            
    1. now click on the `statistics-tutorial` and finally click on hello_world.ipynb; this is the way to open a notebook;
    
    1. simply double-click on any notebook to open it; cell execution is performed with `Ctrl`+`Enter`.
    
 
 1. via [Binder](https://mybinder.org/) - no CERN account needed:
 
    1. go to https://mybinder.org/v2/gh/pinamont/statistics-tutorial/HEAD ;
    it will take a while, but in the end you should get a working environment;

    1. now double-click on hello_world.ipynb; this is the way to open a notebook;
    
    1. simply double-click on any notebook to open it; cell execution is performed with `Ctrl`+`Enter`.


### Step by step

1. Create a workspace from existing histograms and inspect it:
    - directory `create_data`
    - [create_workspace_minimal.ipynb](create_data/create_workspace_minimal.ipynb): very simple example of workspace creation
    - [create_workspace.ipynb](create_data/create_workspace.ipynb): actual exercise we perform to create the workspace needed for the next steps
    - [inspect_workspace.ipynb](create_data/inspect_workspace.ipynb): workspace inspection, visualization of stored histograms, comparison of workspaces
1. Perform fits and understand results:
    - directory `fit`
    - [simple_fit.ipynb](fit/simple_fit.ipynb): how to perform a fit and how to get fit results
<!--     - [covmatrix.ipynb](fit/covmatrix.ipynb): visualization of correlation matrix of the fitted parameters -->
    - [postfit_plots.ipynb](fit/postfit_plots.ipynb): very simple visualization of post-fit distributions from workspace
<!--     - [yield_tables.ipynb](fit/yield_tables.ipynb): more elaborate inspection of effect of fit results, creating yield tables -->
1. Quantify the effect of the systematics on a measurement:
    - directory `systematics`
    - [ranking.ipynb](systematics/ranking.ipynb)
    - [impact_table.ipynb](systematics/impact_table.ipynb)
1. Exclusion limit extraction:
    - directory `limit`
<!--     - [asymptotics.ipynb](limit/asymptotics.ipynb): profile-likelihood ratio limits with asymptotic formulae -->
    - [toys.ipynb](limit/toys.ipynb): setting limits with toys (or asymptotics) for profile-likelihood and other test statistics
1. Quantification of signal significance:
    - directory `p_values`
    - [pvalues.ipynb](p_values/pvalues.ipynb)

 
