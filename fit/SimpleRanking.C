// Example ROOT macro to extract the impact on the POI of each NP
// How to run it:
//   - make sure the TFile initialization points to the correct path and file name of the input workspace
//   - run the code simply as:
//      root -l -b -q SimpleRanking.C

using namespace RooStats;

void SimpleRanking(){
    
    // open file with workspace
    TFile *f = new TFile("ws/ATLASIT_prova_combined_ATLASIT_prova_model.root");

    // get workspace
    RooWorkspace *w = (RooWorkspace*)f->Get("combined");

    // get data
    RooDataSet *dataset = (RooDataSet*)w->data("obsData");
    
    // silence RooFit completely
    RooMsgService::instance().setGlobalKillBelow(RooFit::FATAL);

    // nominal S+B fit to data
    w->var("mu_ttH")->setVal(0);
    w->var("mu_ttH")->setConstant(false);
    w->pdf("simPdf")->fitTo(*dataset,RooFit::PrintLevel(-1));
    
    // get ModelConfig
    ModelConfig *mc = (ModelConfig*)w->obj("ModelConfig");
    
    // get POI
    RooRealVar *poi = (RooRealVar*)mc->GetParametersOfInterest()->first();
    float mu_hat = poi->getVal();
    float mu_hat_err_up = poi->getErrorHi();
    float mu_hat_err_down = poi->getErrorLo();
    
    // Print nominal fit result
    cout << "---------------------------------" << endl;
    cout << "Nominal fit:" << endl;
    cout << "  POI =";
    cout << Form(" %+.3f",mu_hat);
    cout << Form(" %+.3f",mu_hat_err_up);
    cout << " / ";
    cout << Form(" %+.3f",mu_hat_err_down);
    cout << endl;
    
    // save snapshot, containing paramter values after nominal fit (to be loaded afeterward)
    w->saveSnapshot("nominal_snapshot", *mc->GetPdf()->getParameters(dataset));
    
    // loop on list of nuisance parameters
    for(auto np_tmp : *mc->GetNuisanceParameters()){
        RooRealVar* np = (RooRealVar*)np_tmp;
        
        string np_name = np->GetName();
        
        // exclude parameters that are not "alpha_" (to exclude e.g. normalization factors and keep only NPs associated with systematics)
        if(np_name.find("alpha_")==string::npos) continue;
        
        cout << "---------------------------------" << endl;
        cout << "Impact of NP " << np_name << endl;
        
        // load the snapshot we created before, and save value and error (up/down) of this NP
        w->loadSnapshot("nominal_snapshot");
        float np_value = np->getVal();
        float np_err_up = np->getErrorHi();
        float np_err_down = np->getErrorLo();
        
        // Evaluate post-fit impact:
        //
        // set this NP to +1 sigma
        w->loadSnapshot("nominal_snapshot");
        np->setVal( np_value + np_err_up );
        np->setConstant(true);
        w->pdf("simPdf")->fitTo(*dataset,RooFit::PrintLevel(-1));
        float mu_hat_postfit_up = poi->getVal();
        //
        // set this NP to -1 sigma
        w->loadSnapshot("nominal_snapshot");
        np->setVal( np_value + np_err_down );
        np->setConstant(true);
        w->pdf("simPdf")->fitTo(*dataset,RooFit::PrintLevel(-1));
        float mu_hat_postfit_down = poi->getVal();
        
        // Evaluate pre-fit impact:
        //
        // set this NP to +1
        w->loadSnapshot("nominal_snapshot");
        np->setVal( np_value + 1 );
        np->setConstant(true);
        w->pdf("simPdf")->fitTo(*dataset,RooFit::PrintLevel(-1));
        float mu_hat_prefit_up = poi->getVal();
        //
        // set this NP to -1
        w->loadSnapshot("nominal_snapshot");
        np->setVal( np_value - 1 );
        np->setConstant(true);
        w->pdf("simPdf")->fitTo(*dataset,RooFit::PrintLevel(-1));
        float mu_hat_prefit_down = poi->getVal();
        
        // Print pre-fit impact
        cout << "  Pre-fit  impact = ";
        cout << Form("%+.3f",mu_hat_prefit_up - mu_hat);
        cout << " / ";
        cout << Form("%+.3f",mu_hat_prefit_down - mu_hat);
        cout << endl;
        
        // Print post-fit impact
        cout << "  Post-fit impact = ";
        cout << Form("%+.3f",mu_hat_postfit_up - mu_hat);
        cout << " / ";
        cout << Form("%+.3f",mu_hat_postfit_down - mu_hat);
        cout << endl;
    }
    
    cout << "---------------------------------" << endl;
    
}
