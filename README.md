# Statistics Tutorial - ICTP ATLAS Open Data 2022

## Authors

Michele Pinamonti - INFN Sezione di Trieste

*credits to: Valerio Ippolito - INFN Sezione di Roma*


## Scope
We will go through the typical steps of defining, filling up and analysing a workspace.


## Preliminaries

There are two main ways to run this tutorial: Binder and SWAN.


### Binder

[![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/pinamont/statistics-tutorial/HEAD)

[Binder](https://mybinder.org/) - no CERN account needed:

  1. click on the banner above, or go to [https://mybinder.org/v2/gh/pinamont/statistics-tutorial/HEAD](https://mybinder.org/v2/gh/pinamont/statistics-tutorial/HEAD);
    it will take a while, but in the end you should get a working environment;

  1. now double-click on hello_world.ipynb; this is the way to open a notebook;
    
  1. simply double-click on any notebook to open it; cell execution is performed with `Ctrl`+`Enter`.


### SWAN

[<img class="open_in_swan" data-path="basic" alt="Open this Gallery in SWAN" src="https://swanserver.web.cern.ch/swanserver/images/badge_swan_white_150.png" height=20>][gallery_url]

[gallery_url]:https://cern.ch/swanserver/cgi-bin/go?projurl=https://github.com/pinamont/statistics-tutorial.git

<!-- [![SWAN](https://swanserver.web.cern.ch/swanserver/images/badge_swan_white_150.png =100x)](https://cern.ch/swanserver/cgi-bin/go?projurl=https://github.com/pinamont/statistics-tutorial.git) -->

[SWAN](https://swan.web.cern.ch/swan/) - CERN account needed:

  1. *preliminary steps*: 
  
      + go to [cernbox](http://cernbox.cern.ch) and make sure you have a personal EOS folder;

      + in cernbox, go to `SWAN_projetcs/` (single click from the web-browser interface) and create a new text file `config.sh`, with this content:

            #!/bin/bash
            export PYTHONPATH=$CERNBOX_HOME/.local/lib/python3.9/site-packages:$PYTHONPATH


  1. click on the banner above, or go to [https://cern.ch/swanserver/cgi-bin/go?projurl=https://github.com/pinamont/statistics-tutorial.git](https://cern.ch/swanserver/cgi-bin/go?projurl=https://github.com/pinamont/statistics-tutorial.git);
  
  1. configure an environment with:
    * software stack: 101 (NB: this is **not** the default - the code will not work properly with later stack)
    * platform: CentOS7 (gcc8) as platform (NB: this is **not** the default - the code will not work properly with later )
    * 2 cores, 8 GB of memory and no spark cluster (these ones should be set by default)
    * environment script: the script you created, i.e. `$CERNBOX_HOME/SWAN_projects/config.sh`

  1. click on `hello_world.ipynb`; this is the way to open a notebook;

  1. simply double-click on any notebook to open it; cell execution is performed with `Ctrl`+`Enter`.
    


<!--   1. go to [https://swan-k8s.cern.ch/hub/spawn](https://swan-k8s.cern.ch/hub/spawn); -->
<!--   1. create a new project (clicking on the `+` at the bottom right, "Add new projetc"), and call it `statistics-tutorial-ICTP`; -->
<!--   1. from a SWAN terminal window (which you can open clicking on the `>_` icon on the top right of the webpage), go to the `$CERNBOX_HOME/SWAN_projects/statistics-tutorial-ICTP` directory and checkout the repository with: -->
<!--           git clone git@github.com:pinamont/statistics-tutorial.git -->
<!--       or -->
<!--           git clone https://github.com/pinamont/statistics-tutorial.git -->
<!--   1. now click on the `statistics-tutorial` and finally  -->


### Step by step

1. Create a workspace from existing histograms and inspect it:
    - directory `create_data`
    - [create_workspace_minimal.ipynb](create_data/create_workspace_minimal.ipynb): very simple example of workspace creation
    - [create_workspace.ipynb](create_data/create_workspace.ipynb): actual exercise we perform to create the workspace needed for the next steps
    - [inspect_workspace.ipynb](create_data/inspect_workspace.ipynb): workspace inspection, visualization of stored histograms, comparison of workspaces
1. Perform fits and understand results:
    - directory `fit`
    - [simple_fit.ipynb](fit/simple_fit.ipynb): how to perform a fit and how to get fit results
    - [postfit_plots.ipynb](fit/postfit_plots.ipynb): very simple visualization of post-fit distributions from workspace
1. Quantify the effect of the systematics on a measurement:
    - directory `systematics`
    - [ranking.ipynb](systematics/ranking.ipynb)
    - [impact_table.ipynb](systematics/impact_table.ipynb)
1. Exclusion limit extraction:
    - directory `limit`
    - [toys.ipynb](limit/toys.ipynb): setting limits with toys (or asymptotics) for profile-likelihood and other test statistics
1. Quantification of signal significance:
    - directory `p_values`
    - [pvalues.ipynb](p_values/pvalues.ipynb)
