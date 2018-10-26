#include "L1_weight.C"
#include <iostream>
#include <fstream>
#include <TH2.h>
#include <TLegend.h>
#include <TH1D.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <THStack.h>
#include <TFile.h>
#include <TLine.h>
#include <TROOT.h>
#include <TChain.h>
#include <TGraphErrors.h>
#include "TObject.h"
#include <algorithm>

using namespace std;
	Double_t massVlep,Mva,pileupWeight,lumiWeight,scalef;
	Double_t photon_drla[6],photon_pt[6],photon_drla2[6],photon_sieie[6],photon_chiso[6],photon_hoe[6],photon_nhiso[6],photon_phoiso[6],photon_eta[6];
	Double_t ptlep1,ptlep2,etalep1,etalep2,l1_weight;
	double lep1_phi_station2_tmp,lep2_phi_station2_tmp;
	double lep1_phi_station2,lep2_phi_station2,lep1_eta_station2,lep2_eta_station2;
	vector<double> vector_pt;
	vector<double>::iterator biggest_pt;
	Int_t nlooseeles,nloosemus,position,size,lep,run_period,HLT_Mu2,HLT_Mu5,photon_isprompt[6];
	Bool_t Photon_cut[6],photon_pevnew[6],LEP;
        Bool_t MvaFlag;
        Int_t bin1=50,bin2=180;
        Double_t low1=0,low2=50;
        Double_t high1=5,high2=400;
	TString dir = "../WAJetfakephoton/drawSR/";
	TString Save = "./fig/";
//	TString Save = "./fig/TSR/";
//	TString Save = "./fig/begin/";
//	TString dir ="/data/pku/home/anying/cms/CMSSW_8_0_26_patch2/analysis_code/MakeTemplate/ZAJetfakeohoton/pesudo/";
//	TString dir = "/data/pku/home/anying/cms/file_in_cms/files_weighted/";
void tr(TTree* tree);
void draw(THStack* hs, TH1D* h1, TH1D* h2, TH1D* h3);
TH1D* filedata(TString name,Bool_t MvaFlag);
TH1D* filemc(TString name,Bool_t MvaFlag);
int main(){
	gStyle->SetOptStat(0);
        MvaFlag=0;
	THStack* hs = new THStack("hs","drla");
	THStack* hhs = new THStack("hhs","Mva");
	TH1D* h1 =filedata("TSRoutDMuon",MvaFlag);
	TH1D* h2 =filemc("TSRoutZA",MvaFlag);
//	TH1D* h3 =filemc("TSRoutZJets_FX",MvaFlag);
	TH1D* h3 =filemc("SR-outZJets_fakephoton_lep",MvaFlag);
	hs->Add(h3);
	hs->Add(h2);
        cout<<"OK"<<endl;
        draw(hs,h1,h2,h3);
	return 1;
}
TH1D* filedata(TString name,Bool_t MvaFlag){
	Double_t m=0,k=0,n=0;
	TH1D* h;
	if(MvaFlag==false) h = new TH1D("h","drla",bin1,low1,high1);
	else               h= new TH1D("h","Mva",bin2,low2,high2);
        TString filename = name + ".root";
	TFile* file = TFile::Open(dir+filename);
	TTree* tree = (TTree*)file->Get("demo");
        cout<<"file: "<<filename<<endl;

        tr(tree);
	cout<<"nentries = "<<tree->GetEntries()<<endl;
	double nentries = tree->GetEntries();
//        nentries=10000;
        bool dataTflag,mcTflag;
	for(Int_t i=0;i<nentries;i++){
		tree->GetEntry(i);
		l1_weight = L1_weight(lep1_phi_station2_tmp, lep2_phi_station2_tmp, lep1_eta_station2, lep2_eta_station2);
      for(Int_t j=0;j<6;j++){
              if(photon_drla[j]==10) photon_drla[j]=0;
         }
		if(i%10000000==0) cout<<i<<" "<<nentries<<endl;
			LEP = l1_weight==1  && lep==13 && ptlep1 >20. && ptlep2 >20.&& abs(etalep1) <2.4 &&abs(etalep2) < 2.4 && nlooseeles == 0 && nloosemus < 3 && ((run_period<7 && HLT_Mu5 > 0)|| (run_period==7 && HLT_Mu2 > 0)) && massVlep>20 && massVlep<200; 
//			LEP = l1_weight==1 && HLT_Mu2 > 0 && lep==13 && ptlep1 >20. && ptlep2 >20.&& abs(etalep1) <2.4 &&abs(etalep2) < 2.4 && nlooseeles == 0 && nloosemus < 3;/*cout<<name<<endl;*/
		for(Int_t j=0;j<6;j++)
		{
			Photon_cut[j]=/*photon_pev[j]==1*/ photon_pevnew[j]==1&&
					photon_hoe[j]<0.0396 &&
					photon_chiso[j]<0.441 &&
					photon_sieie[j]<0.01022 &&
					photon_nhiso[j]<2.725 + 0.0148*photon_pt[j] + 0.000017*photon_pt[j]*photon_pt[j] &&
					photon_phoiso[j]<2.571 + 0.0047*photon_pt[j]&&
					fabs(photon_eta[j])<1.4442 &&
					/*photon_drla[j]>0.4 && photon_drla2[j]>0.4 &&*/
					photon_pt[j]>25;
			if(Photon_cut[j]&&LEP){
				if(i%10000==0){cout<<"ok!"<<endl;}
				vector_pt.push_back(photon_pt[j]);}
			else   {vector_pt.push_back(0);}
		}//fill the vector_pt
		size=vector_pt.size();
		biggest_pt = max_element(begin(vector_pt),end(vector_pt));
		position = distance( begin(vector_pt), biggest_pt);
		if(*biggest_pt==0){
			vector_pt.clear();
			continue;}
		if(i%10000==0) cout<<i<<"; the biggest pt = "<<*biggest_pt<<"; the position = "<<position<<endl;
		if(MvaFlag==false) {h->Fill(photon_drla[position]/*,scalef*pileupWeight*lumiWeight*35.86*0.96*/);m++;}
		if(MvaFlag==true)  h->Fill(Mva);
		vector_pt.clear();
	}
	if(name.Contains("DMuon")) cout<<"m "<<m<<endl;
	if(name.Contains("ZA"))    cout<<"k "<<k<<endl;
	if(name.Contains("ZJets")) cout<<"n "<<n<<endl;
	file->Close();
	return h;
}
TH1D* filemc(TString name,Bool_t MvaFlag){
	Double_t m=0,k=0,n=0;
        TH1D* hh;
	if(MvaFlag==false)  hh = new TH1D("hh","drla",bin1,low1,high1);
	if(MvaFlag==true)   hh = new TH1D("hh","Mva",bin2,low2,high2);

        TString filename = name + ".root";
	TFile* file = TFile::Open(dir+filename);
	TTree* tree = (TTree*)file->Get("demo");
        cout<<"file: "<<filename<<endl;

        tr(tree);
        cout<<"lep = "<<lep<<endl;
	cout<<"nentries = "<<tree->GetEntries()<<endl;
	double nentries = tree->GetEntries();
//        nentries=10000;
        bool dataTflag,mcTflag;
	for(Int_t i=0;i<nentries;i++){
		tree->GetEntry(i);
		l1_weight = L1_weight(lep1_phi_station2_tmp, lep2_phi_station2_tmp, lep1_eta_station2, lep2_eta_station2);
      for(Int_t j=0;j<6;j++){
              if(photon_drla[j]==10) photon_drla[j]=0;
         }
		if(i%10000000==0) cout<<i<<" "<<nentries<<endl;
			LEP = l1_weight==1 && HLT_Mu2 > 0 && lep==13 && ptlep1 >20. && ptlep2 >20.&& abs(etalep1) <2.4 &&abs(etalep2) < 2.4 && nlooseeles == 0 && nloosemus < 3 && massVlep>20 && massVlep<200;/*cout<<name<<endl;*/
		for(Int_t j=0;j<6;j++)
		{
				Photon_cut[j]=/*photon_pev[j]==1*/photon_pevnew[j]==1&&
					photon_hoe[j]<0.0396 &&
					photon_chiso[j]<0.441 &&
					photon_sieie[j]<0.01022 &&
					photon_nhiso[j]<2.725 + 0.0148*photon_pt[j] + 0.000017*photon_pt[j]*photon_pt[j] &&
					photon_phoiso[j]<2.571 + 0.0047*photon_pt[j]&&
					fabs(photon_eta[j])<1.4442 &&
					photon_pt[j]>25/*&&
					photon_drla[j]>0.4 && photon_drla2[j]>0.4*/;
			if(Photon_cut[j]&&LEP){
				if(i%10000000==0){cout<<"ok!"<<endl;}
				vector_pt.push_back(photon_pt[j]);}
			else   {vector_pt.push_back(0);}
		}//fill the vector_pt
		size=vector_pt.size();
		biggest_pt = max_element(begin(vector_pt),end(vector_pt));
		position = distance( begin(vector_pt), biggest_pt);
		if(*biggest_pt==0){
			vector_pt.clear();
			continue;}
		if(i%10000==0) cout<<i<<"; the biggest pt = "<<*biggest_pt<<"; the position = "<<position<<endl;
		if(MvaFlag==false)
		{
			if(name.Contains("ZJets") && photon_isprompt[position]==-1/*&&massVlep<100 && massVlep>80 && Mva >101 && photon_drla[position]>1 && photon_drla2[position]>1 */)	
				{hh->Fill(photon_drla[position],scalef*pileupWeight*lumiWeight*35.86*0.96);m++;}
			if(name.Contains("ZA") && photon_isprompt[position]==1/* && massVlep>80 && Mva>81 && Mva<101 && photon_drla[position]>0.4 && photon_drla2[position]>0.4*/)	
				{hh->Fill(photon_drla[position],scalef*pileupWeight*lumiWeight*35.86*0.96);m++;}
		}
		if(MvaFlag==true) hh->Fill(Mva,scalef*pileupWeight*lumiWeight*35.86*0.96);
		vector_pt.clear();
	}
	if(name.Contains("DMuon")) cout<<"number "<<m<<endl;
	if(name.Contains("ZA"))    cout<<"number "<<m<<endl;
	if(name.Contains("ZJets")) cout<<"number "<<m<<endl;
	file->Close();
	return hh;
}
void tr(TTree* tree){
	tree->SetBranchAddress("photon_isprompt",photon_isprompt);
	tree->SetBranchAddress("scalef",&scalef);
	tree->SetBranchAddress("pileupWeight",&pileupWeight);
	tree->SetBranchAddress("lumiWeight",&lumiWeight);
	tree->SetBranchAddress("massVlep",&massVlep);
	tree->SetBranchAddress("Mva",&Mva);
	tree->SetBranchAddress("lep",&lep);
	tree->SetBranchAddress("run_period",&run_period);
	tree->SetBranchAddress("HLT_Mu2",&HLT_Mu2);
	tree->SetBranchAddress("HLT_Mu5",&HLT_Mu5);
	tree->SetBranchAddress("l1_weight",&l1_weight);
	tree->SetBranchAddress("lep1_phi_station2",&lep1_phi_station2);
	tree->SetBranchAddress("lep2_phi_station2",&lep2_phi_station2);
	tree->SetBranchAddress("lep1_eta_station2",&lep1_eta_station2);
	tree->SetBranchAddress("lep2_eta_station2",&lep2_eta_station2);

	tree->SetBranchAddress("photon_hoe",photon_hoe);
	tree->SetBranchAddress("photon_nhiso",photon_nhiso);
	tree->SetBranchAddress("photon_phoiso",photon_phoiso);
	tree->SetBranchAddress("photon_pt",photon_pt);
	tree->SetBranchAddress("photon_eta",photon_eta);
	tree->SetBranchAddress("nloosemus",&nloosemus);
	tree->SetBranchAddress("nlooseeles",&nlooseeles);
	tree->SetBranchAddress("ptlep1",&ptlep1);
	tree->SetBranchAddress("ptlep2",&ptlep2);
	tree->SetBranchAddress("etalep1",&etalep1);
	tree->SetBranchAddress("etalep2",&etalep2);
	tree->SetBranchAddress("photon_drla",photon_drla);
	tree->SetBranchAddress("photon_drla2",photon_drla2);
	tree->SetBranchAddress("photon_sieie",photon_sieie);
	tree->SetBranchAddress("photon_chiso",photon_chiso);
	tree->SetBranchAddress("photon_pt",photon_pt);
	tree->SetBranchAddress("photon_pevnew",photon_pevnew);
}
void draw(THStack* hs, TH1D* h1, TH1D* h2, TH1D* h3){
	gStyle->SetPadBorderMode(0);
	gStyle->SetOptStat(0);
	gStyle->SetPadGridX(1);
	gStyle->SetPadGridY(1);
	gStyle->SetPadTickX(1);
	gStyle->SetPadTickY(1);
	gStyle->SetPadTopMargin(0.07);
	gStyle->SetPadBottomMargin(0.3);
	gStyle->SetPadRightMargin(0.05);
	gStyle->SetPadLeftMargin(0.14);
	gStyle->SetPadTickX(1);
	gStyle->SetPadTickY(1);
	gStyle->SetAxisColor(1, "XYZ");
	gStyle->SetStripDecimals(kTRUE);
	gStyle->SetTickLength(0.03, "XYZ");
	gStyle->SetNdivisions(510, "XYZ");

        int number = h1->GetNbinsX();
        cout<<"number = "<<number<<endl;
	double nsigma_x[number],nsigma_y[number] ;
	double nsigma_ex[number],nsigma_ey[number] ;
        TH1D* hist = (TH1D*)h2->Clone();
        hist->Add(h3,1);
	for (int ibin = 0; ibin != h1->GetNbinsX(); ibin++) {
                        double Data = h1->GetBinContent(ibin + 1);
                        double Bkg = hist->GetBinContent(ibin + 1);
			double x = h1->GetBinCenter(ibin + 1);
                        double eData = h1->GetBinError(ibin + 1);
                        double eBkg = hist->GetBinError(ibin + 1);

			if (Data !=0 && Bkg !=0 ){
				nsigma_x[ibin] = x;
				nsigma_y[ibin] = Data / Bkg;
				nsigma_ex[ibin] = h1->GetBinWidth(ibin+1)/2.;
                                nsigma_ey[ibin] = sqrt((eData*eData/(Bkg*Bkg)) + (Data*Data*eBkg*eBkg/(Bkg*Bkg*Bkg*Bkg)));

			}
			else {
				nsigma_x[ibin] = 0; 
				nsigma_y[ibin] = 0;
				nsigma_ex[ibin] = 0;
                                nsigma_ey[ibin] = 0;
			}
	}
	TCanvas* c1 = new TCanvas("c1","",750,500);
	c1->SetGrid();

	TPad *top_pad=new TPad("top_pad", "top_pad",0,0.2, 1.0, 1.0);
	top_pad->Draw();
	top_pad->cd();
	top_pad->SetBottomMargin(0.1);
	TLegend* t1 = new TLegend(0.7,0.7,0.9,0.9);
	h2->SetLineColor(2);
        h2->SetFillColor(2);
	h3->SetLineColor(3);
        h3->SetFillColor(3);
	h1->SetLineColor(kBlack);
	h1->SetMarkerStyle(20);
        t1->AddEntry(h1,"Data");
        t1->AddEntry(h2,"ZA");
        t1->AddEntry(h3,"ZJets");
        hs->Draw(" hist");
        h1->Draw("same PE");
        t1->Draw();

        cout<<"OK3"<<endl;
	c1->cd();
	TLine* line1 = new TLine(low1,1.,high1,1);
	TPad *bottom_pad=new TPad("bottom_pad", "bottom_pad", 0, 0., 1.0, 0.2);
	TGraphErrors *gr = new TGraphErrors(number,nsigma_x, nsigma_y,nsigma_ex,nsigma_ey);
	bottom_pad->Draw();
	bottom_pad->cd();
	bottom_pad->SetTopMargin(0);
        gr->Draw("ape");
        gr->SetMarkerStyle(20);
        gr->SetTitle("");
        gr->GetXaxis()->SetTitle( "drla ");
        gr->GetYaxis()->SetTitle("Data / MC ");
        gr->GetXaxis()->SetRangeUser(low1,high1);
        gr->GetXaxis()->CenterTitle();
        gr->GetYaxis()->CenterTitle();
        gr->SetLineColor(kBlack);
        gr->GetXaxis()->SetTitleOffset(0.9);
        gr->GetYaxis()->SetTitleOffset(0.22);
        gr->GetXaxis()->SetTitleSize(0.15);
        gr->GetYaxis()->SetTitleSize(0.15);
        gr->GetXaxis()->SetLabelSize(0.12);
        gr->GetYaxis()->SetLabelSize(0.1);
        gr->SetMaximum(1.35);
        gr->SetMinimum(0.7);
        line1->SetLineColor(kRed);
        line1->Draw();

        if(MvaFlag==false){c1->Draw();c1->Print(Save+"drla.eps");c1->Print(Save+"drla.C");top_pad->SetLogy();c1->Print(Save+"drla_log.eps");c1->Print(Save+"drla_log.C");}
	if(MvaFlag==true) {c1->Print(Save+"Mva.eps");c1->Print(Save+"Mva.eps");}

	TCanvas* can = new TCanvas("can","",900,600);
	TLegend* t2 = new TLegend(0.7,0.7,0.9,0.9);
        h2->SetFillColor(0);
	h3->SetFillColor(0);
        t2->AddEntry(h2,"ZA");
        t2->AddEntry(h3,"ZJets");
        h2->Draw(" hist");
        h3->Draw("same hist");
	t2->Draw();
	can->Print(Save+"drla_zaAndzj.eps");
}
