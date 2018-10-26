#define draw_cxx
#include "draw.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <TH1.h>
#include "L1_weight.C"

using namespace std;
void draw::Loop(TString name)
{
//   In a ROOT session, you can do:
//      root> .L draw.C
//      root> draw t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nbytes = 0, nb = 0;
   double lep1_phi_station2_tmp = 0;
   double lep2_phi_station2_tmp = 0;

   TString hname="h_"+name;
   Bool_t PHOTON,LEP;
   Double_t pt[10]={25,30,35,40,45,50,60,80,120,400};
   h1 = new TH1F(hname,hname,9,pt);
//   nentries=100;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
  // if (Cut(ientry) < 0) continue;
      lep1_phi_station2_tmp = lep1_phi_station2;
      lep2_phi_station2_tmp = lep2_phi_station2;
      if(lep1_phi_station2<0) lep1_phi_station2_tmp = lep1_phi_station2+6.28319;
      if(lep2_phi_station2<0) lep2_phi_station2_tmp = lep2_phi_station2+6.28319;
      l1_weight = L1_weight(lep1_phi_station2_tmp, lep2_phi_station2_tmp, lep1_eta_station2, lep2_eta_station2);
  
      LEP=l1_weight==1 && lep == 13 && ((run_period<7 && HLT_Mu5 > 0)|| (run_period==7 && HLT_Mu2 > 0)) && ptlep1 > 20. && ptlep2 > 20. && fabs(etalep1) < 2.4 && fabs(etalep2) < 2.4  && nlooseeles == 0 && nloosemus < 3 && massVlep > 70. && massVlep < 110.;
      PHOTON= /*photonet<400&&*/photonet>25 &&((abs(photoneta)<2.5&&fabs(photoneta)>1.566) || (fabs(photoneta)<1.4442) );
      if(LEP&&PHOTON==true)
      h1->Fill(photonet);    
   }
}
