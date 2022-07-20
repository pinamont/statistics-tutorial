# Statistics Tutorial - ICTP ATLAS Open Data 2022

## Authors

Michele Pinamonti - INFN Sezione di Trieste

*credits to: Valerio Ippolito - INFN Sezione di Roma*

## Scope
We will go through the typical steps of defining, filling up and analysing a workspace.

## Preliminaries

[![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/pinamont/statistics-tutorial/HEAD)
 
### Run on Binder
The easiest way to run notebooks is via [Binder](https://mybinder.org/):

 1. go to https://mybinder.org/v2/gh/pinamont/statistics-tutorial/HEAD ;
 it will take a while, but in the end you should get a working environment;

 1. now double-click on hello_world.ipynb; this is the way to open a notebook;
  
 1. simply double-click on any notebook to open it; cell execution is performed with `Ctrl`+`Enter`


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

 
