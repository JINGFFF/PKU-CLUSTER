#define SRplot_cxx
#include "SRplot.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
using namespace std;
void SRplot::Loop(TString name)
{
//   In a ROOT session, you can do:
//      root> .L SRplot.C
//      root> SRplot t
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
   vector<double> vector_pt;
   vector<double>::iterator biggest_pt;
   Int_t position,size;
   Bool_t Photon_cut[6],LEP;
   double m=0,n=0,k=0;
   cout<<nentries<<endl;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      if(jentry%100000==0) cout<<jentry<<" "<<nentries<<endl;
      // if (Cut(ientry) < 0) continue;
                if(name.Contains("Muon"))
			{LEP = l1_weight==1  && lep==13 && ptlep1 >20. && ptlep2 >20.&& abs(etalep1) <2.4 &&abs(etalep2) < 2.4 && nlooseeles == 0 && nloosemus < 3 && ((run_period<7 && HLT_Mu5 > 0)|| (run_period==7 && HLT_Mu2 > 0)); /*cout<<name<<endl;*/}
                if(name.Contains("Z"))
			{LEP = l1_weight==1 && HLT_Mu2 > 0 && lep==13 && ptlep1 >20. && ptlep2 >20.&& abs(etalep1) <2.4 &&abs(etalep2) < 2.4 && nlooseeles == 0 && nloosemus < 3;/*cout<<name<<endl;*/}

		for(Int_t j=0;j<6;j++)
		{
				Photon_cut[j]=/*photon_pev[j]==1*/photon_pevnew[j]==1&&
					photon_hoe[j]<0.0396 &&
					photon_chiso[j]<0.441 &&
					photon_nhiso[j]<2.725 + 0.0148*photon_pt[j] + 0.000017*photon_pt[j]*photon_pt[j] &&
					photon_phoiso[j]<2.571 + 0.0047*photon_pt[j]&&
					fabs(photon_eta[j])<1.4442 &&
					photon_pt[j]>10;
			if(Photon_cut[j]&&LEP){
				vector_pt.push_back(photon_pt[j]);}
			else   {vector_pt.push_back(0);}
		}//fill the vector_pt
		size=vector_pt.size();
		biggest_pt = max_element(begin(vector_pt),end(vector_pt));
		position = distance( begin(vector_pt), biggest_pt);
		if(*biggest_pt==0){
			vector_pt.clear();
			continue;}
		if(jentry%20000==0) cout<<jentry<<"; the biggest pt = "<<*biggest_pt<<"; the position = "<<position<<endl;
		if(name.Contains("DMuon"))
	         	{
				h1->Fill(massVlep);m++;
				hh1->Fill(Mva);
			}

		if(name.Contains("ZJets"))
		        {
				h3->Fill(massVlep,scalef*pileupWeight*lumiWeight*35.8*0.96);n++;
				hh3->Fill(Mva,scalef*pileupWeight*lumiWeight*35.8*0.96);
			}
		if(name.Contains("ZA"))
		        {
				h2->Fill(massVlep,scalef*pileupWeight*lumiWeight*35.8*0.96);k++;
				hh2->Fill(Mva,scalef*pileupWeight*lumiWeight*35.8*0.96);
			}
		vector_pt.clear();
	}
	if(name.Contains("DMuon")) cout<<"m "<<m<<endl;
	if(name.Contains("ZA"))    cout<<"k "<<k<<endl;
	if(name.Contains("ZJets")) cout<<"n "<<n<<endl;

   }
