#include "SRplot.C"
#include <iostream>
#include <fstream>
using namespace std;

void runxx() {
//TString dir="/data/pku/home/anying/cms/file_in_cms/files_weighted/";
TString dir = "../WAJetfakephoton/drawSR/";
ifstream infile("file");
string buffer;
TString name;
TString sss;

int k=2;

   while(k>0){
      getline (infile, buffer) ;
      name = buffer;
      if(!(name.Contains("end"))){ 
         TString filename= name+".root";
         cout<<name<<endl;
         TFile *file1 =new TFile(dir+filename);
         TTree *tree1 = (TTree*) file1->Get("demo");
         SRplot m1(tree1);
         cout<<filename<<endl;
	 m1.Loop(filename);
        }
      if(name.Contains("end")){
         k=-2;continue;
       }
    }
 }
int main(){
    runxx();
	TCanvas* c1 = new TCanvas("c1","",900,600);
	c1->SetGrid();
  //      c1->SetLogy();
	TLegend* t1 = new TLegend(0.7,0.7,0.9,0.9);
	h2->SetLineColor(2);
        h2->SetFillColor(2);
	h3->SetLineColor(3);
        h3->SetFillColor(3);
	h1->SetLineColor(kBlack);
	h1->SetMarkerStyle(20);
        t1->AddEntry("h1","Data","L");
        t1->AddEntry("h2","ZA","L");
        t1->AddEntry("h3","ZJets","L");
	hs->Add(h3);
	hs->Add(h2);
        hs->Draw(" hist");
        h1->Draw("same PE");
        t1->Draw();
        c1->Print("./fig/massVlep.eps");
        cout<<"massVlep saved"<<endl;

	TCanvas* can = new TCanvas("can","",900,600);
	TLegend* t2 = new TLegend(0.7,0.7,0.9,0.9);
	can->SetGrid();
//        can->SetLogy();
	hh2->SetLineColor(2);
        hh2->SetFillColor(2);
	hh3->SetLineColor(3);
        hh3->SetFillColor(3);
	hh1->SetLineColor(kBlack);
	hh1->SetMarkerStyle(20);
	hhs->Add(h3);
	hhs->Add(h2);
        t2->AddEntry("hh1","Data","L");
        t2->AddEntry("hh2","ZA","L");
        t2->AddEntry("hh3","ZJets","L");
        hhs->Draw(" hist");
        hh1->Draw("same PE");
	t2->Draw();
        can->Print("./fig/Mva.eps");
        cout<<"Mva saved"<<endl;
    return 1;
  }
