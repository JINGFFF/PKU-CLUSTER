void drla()
{
//=========Macro generated from canvas: c1/
//=========  (Sun Oct 14 22:28:20 2018) by ROOT version6.06/01
   TCanvas *c1 = new TCanvas("c1", "",0,0,750,500);
   gStyle->SetOptStat(0);
   c1->SetHighLightColor(2);
   c1->Range(0,0,1,1);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetGridx();
   c1->SetGridy();
   c1->SetTickx(1);
   c1->SetTicky(1);
   c1->SetLeftMargin(0.14);
   c1->SetRightMargin(0.05);
   c1->SetTopMargin(0.07);
   c1->SetBottomMargin(0.3);
   c1->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: top_pad
   TPad *top_pad = new TPad("top_pad", "top_pad",0,0.2,1,1);
   top_pad->Draw();
   top_pad->cd();
   top_pad->Range(-0.8641975,-172.7664,5.308642,1554.897);
   top_pad->SetFillColor(0);
   top_pad->SetBorderMode(0);
   top_pad->SetBorderSize(2);
   top_pad->SetGridx();
   top_pad->SetGridy();
   top_pad->SetTickx(1);
   top_pad->SetTicky(1);
   top_pad->SetLeftMargin(0.14);
   top_pad->SetRightMargin(0.05);
   top_pad->SetTopMargin(0.07);
   top_pad->SetFrameBorderMode(0);
   top_pad->SetFrameBorderMode(0);
   
   THStack *hs = new THStack();
   hs->SetName("hs");
   hs->SetTitle("drla");
   
   TH1F *hs_stack_1 = new TH1F("hs_stack_1","drla",50,0,5);
   hs_stack_1->SetMinimum(0);
   hs_stack_1->SetMaximum(1433.961);
   hs_stack_1->SetDirectory(0);
   hs_stack_1->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   hs_stack_1->SetLineColor(ci);
   hs_stack_1->GetXaxis()->SetLabelFont(42);
   hs_stack_1->GetXaxis()->SetLabelSize(0.035);
   hs_stack_1->GetXaxis()->SetTitleSize(0.035);
   hs_stack_1->GetXaxis()->SetTitleFont(42);
   hs_stack_1->GetYaxis()->SetLabelFont(42);
   hs_stack_1->GetYaxis()->SetLabelSize(0.035);
   hs_stack_1->GetYaxis()->SetTitleSize(0.035);
   hs_stack_1->GetYaxis()->SetTitleFont(42);
   hs_stack_1->GetZaxis()->SetLabelFont(42);
   hs_stack_1->GetZaxis()->SetLabelSize(0.035);
   hs_stack_1->GetZaxis()->SetTitleSize(0.035);
   hs_stack_1->GetZaxis()->SetTitleFont(42);
   hs->SetHistogram(hs_stack_1);
   
   
   TH1D *hh__1 = new TH1D("hh__1","drla",50,0,5);
   hh__1->SetBinContent(5,21.94818);
   hh__1->SetBinContent(6,23.93879);
   hh__1->SetBinContent(7,29.09886);
   hh__1->SetBinContent(8,23.48512);
   hh__1->SetBinContent(9,35.17603);
   hh__1->SetBinContent(10,40.0285);
   hh__1->SetBinContent(11,33.9836);
   hh__1->SetBinContent(12,35.88516);
   hh__1->SetBinContent(13,29.17556);
   hh__1->SetBinContent(14,52.53803);
   hh__1->SetBinContent(15,30.79388);
   hh__1->SetBinContent(16,45.04387);
   hh__1->SetBinContent(17,36.43889);
   hh__1->SetBinContent(18,35.50245);
   hh__1->SetBinContent(19,37.96554);
   hh__1->SetBinContent(20,41.3369);
   hh__1->SetBinContent(21,40.10906);
   hh__1->SetBinContent(22,55.60217);
   hh__1->SetBinContent(23,33.49321);
   hh__1->SetBinContent(24,42.76367);
   hh__1->SetBinContent(25,59.97376);
   hh__1->SetBinContent(26,42.14966);
   hh__1->SetBinContent(27,52.70954);
   hh__1->SetBinContent(28,46.37188);
   hh__1->SetBinContent(29,45.14393);
   hh__1->SetBinContent(30,71.9669);
   hh__1->SetBinContent(31,51.23261);
   hh__1->SetBinContent(32,47.0419);
   hh__1->SetBinContent(33,29.0029);
   hh__1->SetBinContent(34,23.77017);
   hh__1->SetBinContent(35,25.81552);
   hh__1->SetBinContent(36,11.1977);
   hh__1->SetBinContent(37,21.40752);
   hh__1->SetBinContent(38,12.54302);
   hh__1->SetBinContent(39,9.783087);
   hh__1->SetBinContent(40,10.03566);
   hh__1->SetBinContent(41,1.013495);
   hh__1->SetBinContent(43,4.585593);
   hh__1->SetBinContent(44,4.050971);
   hh__1->SetBinError(5,5.870847);
   hh__1->SetBinError(6,5.934031);
   hh__1->SetBinError(7,6.590324);
   hh__1->SetBinError(8,5.951062);
   hh__1->SetBinError(9,7.240347);
   hh__1->SetBinError(10,7.768587);
   hh__1->SetBinError(11,7.009809);
   hh__1->SetBinError(12,7.359417);
   hh__1->SetBinError(13,6.595968);
   hh__1->SetBinError(14,8.83701);
   hh__1->SetBinError(15,6.762173);
   hh__1->SetBinError(16,8.228016);
   hh__1->SetBinError(17,7.39299);
   hh__1->SetBinError(18,7.317745);
   hh__1->SetBinError(19,7.526926);
   hh__1->SetBinError(20,7.921323);
   hh__1->SetBinError(21,7.616359);
   hh__1->SetBinError(22,8.968702);
   hh__1->SetBinError(23,6.960842);
   hh__1->SetBinError(24,7.939083);
   hh__1->SetBinError(25,9.478143);
   hh__1->SetBinError(26,7.728014);
   hh__1->SetBinError(27,8.831806);
   hh__1->SetBinError(28,8.20789);
   hh__1->SetBinError(29,8.117953);
   hh__1->SetBinError(30,10.32234);
   hh__1->SetBinError(31,8.823294);
   hh__1->SetBinError(32,8.441064);
   hh__1->SetBinError(33,6.656388);
   hh__1->SetBinError(34,5.980089);
   hh__1->SetBinError(35,6.178123);
   hh__1->SetBinError(36,4.025124);
   hh__1->SetBinError(37,5.743099);
   hh__1->SetBinError(38,4.313331);
   hh__1->SetBinError(39,3.718883);
   hh__1->SetBinError(40,3.819834);
   hh__1->SetBinError(41,1.013495);
   hh__1->SetBinError(43,2.648044);
   hh__1->SetBinError(44,2.375359);
   hh__1->SetEntries(974);
   hh__1->SetStats(0);
   hh__1->SetFillColor(3);
   hh__1->SetLineColor(3);
   hh__1->GetXaxis()->SetLabelFont(42);
   hh__1->GetXaxis()->SetLabelSize(0.035);
   hh__1->GetXaxis()->SetTitleSize(0.035);
   hh__1->GetXaxis()->SetTitleFont(42);
   hh__1->GetYaxis()->SetLabelFont(42);
   hh__1->GetYaxis()->SetLabelSize(0.035);
   hh__1->GetYaxis()->SetTitleSize(0.035);
   hh__1->GetYaxis()->SetTitleFont(42);
   hh__1->GetZaxis()->SetLabelFont(42);
   hh__1->GetZaxis()->SetLabelSize(0.035);
   hh__1->GetZaxis()->SetTitleSize(0.035);
   hh__1->GetZaxis()->SetTitleFont(42);
   hs->Add(hh,"");
   
   TH1D *hh__2 = new TH1D("hh__2","drla",50,0,5);
   hh__2->SetBinContent(5,500.6078);
   hh__2->SetBinContent(6,480.0854);
   hh__2->SetBinContent(7,392.4358);
   hh__2->SetBinContent(8,357.1386);
   hh__2->SetBinContent(9,319.2454);
   hh__2->SetBinContent(10,311.7229);
   hh__2->SetBinContent(11,311.1523);
   hh__2->SetBinContent(12,302.7941);
   hh__2->SetBinContent(13,291.0131);
   hh__2->SetBinContent(14,287.2601);
   hh__2->SetBinContent(15,303.6529);
   hh__2->SetBinContent(16,290.2108);
   hh__2->SetBinContent(17,349.5163);
   hh__2->SetBinContent(18,365.671);
   hh__2->SetBinContent(19,378.2494);
   hh__2->SetBinContent(20,457.4567);
   hh__2->SetBinContent(21,545.9055);
   hh__2->SetBinContent(22,644.5175);
   hh__2->SetBinContent(23,752.0125);
   hh__2->SetBinContent(24,888.7211);
   hh__2->SetBinContent(25,994.2036);
   hh__2->SetBinContent(26,1122.498);
   hh__2->SetBinContent(27,1177.934);
   hh__2->SetBinContent(28,1245.275);
   hh__2->SetBinContent(29,1278.583);
   hh__2->SetBinContent(30,1293.71);
   hh__2->SetBinContent(31,1296.658);
   hh__2->SetBinContent(32,1041.075);
   hh__2->SetBinContent(33,497.4563);
   hh__2->SetBinContent(34,280.2477);
   hh__2->SetBinContent(35,202.5679);
   hh__2->SetBinContent(36,137.3068);
   hh__2->SetBinContent(37,91.6644);
   hh__2->SetBinContent(38,59.89496);
   hh__2->SetBinContent(39,48.4438);
   hh__2->SetBinContent(40,31.69397);
   hh__2->SetBinContent(41,24.14339);
   hh__2->SetBinContent(42,11.72696);
   hh__2->SetBinContent(43,8.431759);
   hh__2->SetBinContent(44,7.047518);
   hh__2->SetBinContent(45,7.141304);
   hh__2->SetBinContent(46,3.065558);
   hh__2->SetBinContent(47,2.21925);
   hh__2->SetBinContent(48,0.525484);
   hh__2->SetBinError(5,15.01506);
   hh__2->SetBinError(6,14.44097);
   hh__2->SetBinError(7,13.42049);
   hh__2->SetBinError(8,12.75643);
   hh__2->SetBinError(9,12.1456);
   hh__2->SetBinError(10,11.82766);
   hh__2->SetBinError(11,11.8114);
   hh__2->SetBinError(12,11.42312);
   hh__2->SetBinError(13,11.52644);
   hh__2->SetBinError(14,11.46309);
   hh__2->SetBinError(15,11.50864);
   hh__2->SetBinError(16,11.4174);
   hh__2->SetBinError(17,12.06489);
   hh__2->SetBinError(18,12.25884);
   hh__2->SetBinError(19,12.67217);
   hh__2->SetBinError(20,13.43582);
   hh__2->SetBinError(21,14.35639);
   hh__2->SetBinError(22,15.37812);
   hh__2->SetBinError(23,16.71817);
   hh__2->SetBinError(24,17.72181);
   hh__2->SetBinError(25,18.74843);
   hh__2->SetBinError(26,19.92068);
   hh__2->SetBinError(27,20.43318);
   hh__2->SetBinError(28,21.04197);
   hh__2->SetBinError(29,21.27955);
   hh__2->SetBinError(30,21.49718);
   hh__2->SetBinError(31,21.49469);
   hh__2->SetBinError(32,19.43721);
   hh__2->SetBinError(33,13.46596);
   hh__2->SetBinError(34,10.47358);
   hh__2->SetBinError(35,8.756694);
   hh__2->SetBinError(36,7.157302);
   hh__2->SetBinError(37,5.999616);
   hh__2->SetBinError(38,5.043216);
   hh__2->SetBinError(39,4.213293);
   hh__2->SetBinError(40,3.427425);
   hh__2->SetBinError(41,2.894131);
   hh__2->SetBinError(42,2.225263);
   hh__2->SetBinError(43,1.872554);
   hh__2->SetBinError(44,1.589837);
   hh__2->SetBinError(45,1.430205);
   hh__2->SetBinError(46,1.142339);
   hh__2->SetBinError(47,0.7535016);
   hh__2->SetBinError(48,0.4763749);
   hh__2->SetEntries(127595);
   hh__2->SetDirectory(0);
   hh__2->SetStats(0);
   hh__2->SetFillColor(2);
   hh__2->SetLineColor(2);
   hh__2->GetXaxis()->SetLabelFont(42);
   hh__2->GetXaxis()->SetLabelSize(0.035);
   hh__2->GetXaxis()->SetTitleSize(0.035);
   hh__2->GetXaxis()->SetTitleFont(42);
   hh__2->GetYaxis()->SetLabelFont(42);
   hh__2->GetYaxis()->SetLabelSize(0.035);
   hh__2->GetYaxis()->SetTitleSize(0.035);
   hh__2->GetYaxis()->SetTitleFont(42);
   hh__2->GetZaxis()->SetLabelFont(42);
   hh__2->GetZaxis()->SetLabelSize(0.035);
   hh__2->GetZaxis()->SetTitleSize(0.035);
   hh__2->GetZaxis()->SetTitleFont(42);
   hs->Add(hh,"");
   hs->Draw("hist");
   
   TH1D *h__3 = new TH1D("h__3","drla",50,0,5);
   h__3->SetBinContent(5,433);
   h__3->SetBinContent(6,368);
   h__3->SetBinContent(7,323);
   h__3->SetBinContent(8,326);
   h__3->SetBinContent(9,275);
   h__3->SetBinContent(10,301);
   h__3->SetBinContent(11,287);
   h__3->SetBinContent(12,286);
   h__3->SetBinContent(13,272);
   h__3->SetBinContent(14,307);
   h__3->SetBinContent(15,326);
   h__3->SetBinContent(16,342);
   h__3->SetBinContent(17,362);
   h__3->SetBinContent(18,368);
   h__3->SetBinContent(19,397);
   h__3->SetBinContent(20,525);
   h__3->SetBinContent(21,592);
   h__3->SetBinContent(22,668);
   h__3->SetBinContent(23,818);
   h__3->SetBinContent(24,893);
   h__3->SetBinContent(25,977);
   h__3->SetBinContent(26,1175);
   h__3->SetBinContent(27,1228);
   h__3->SetBinContent(28,1290);
   h__3->SetBinContent(29,1320);
   h__3->SetBinContent(30,1415);
   h__3->SetBinContent(31,1309);
   h__3->SetBinContent(32,1043);
   h__3->SetBinContent(33,607);
   h__3->SetBinContent(34,337);
   h__3->SetBinContent(35,255);
   h__3->SetBinContent(36,186);
   h__3->SetBinContent(37,121);
   h__3->SetBinContent(38,79);
   h__3->SetBinContent(39,56);
   h__3->SetBinContent(40,50);
   h__3->SetBinContent(41,39);
   h__3->SetBinContent(42,29);
   h__3->SetBinContent(43,18);
   h__3->SetBinContent(44,15);
   h__3->SetBinContent(45,4);
   h__3->SetBinContent(46,5);
   h__3->SetEntries(20027);
   h__3->SetStats(0);
   h__3->SetMarkerStyle(20);
   h__3->GetXaxis()->SetLabelFont(42);
   h__3->GetXaxis()->SetLabelSize(0.035);
   h__3->GetXaxis()->SetTitleSize(0.035);
   h__3->GetXaxis()->SetTitleFont(42);
   h__3->GetYaxis()->SetLabelFont(42);
   h__3->GetYaxis()->SetLabelSize(0.035);
   h__3->GetYaxis()->SetTitleSize(0.035);
   h__3->GetYaxis()->SetTitleFont(42);
   h__3->GetZaxis()->SetLabelFont(42);
   h__3->GetZaxis()->SetLabelSize(0.035);
   h__3->GetZaxis()->SetTitleSize(0.035);
   h__3->GetZaxis()->SetTitleFont(42);
   h__3->Draw("same PE");
   
   TLegend *leg = new TLegend(0.7,0.7,0.9,0.9,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("h","Data","lpf");
   entry->SetFillStyle(1001);
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("hh","ZA","lpf");
   entry->SetFillColor(2);
   entry->SetFillStyle(1001);
   entry->SetLineColor(2);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(1);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("hh","ZJets","lpf");
   entry->SetFillColor(3);
   entry->SetFillStyle(1001);
   entry->SetLineColor(3);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(1);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TPaveText *pt = new TPaveText(0.4665416,0.94,0.5334584,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *AText = pt->AddText("drla");
   pt->Draw();
   top_pad->Modified();
   c1->cd();
  
// ------------>Primitives in pad: bottom_pad
   TPad *bottom_pad = new TPad("bottom_pad", "bottom_pad",0,0,1,0.2);
   bottom_pad->Draw();
   bottom_pad->cd();
   bottom_pad->Range(-0.8658222,0.4214286,5.318622,1.35);
   bottom_pad->SetFillColor(0);
   bottom_pad->SetBorderMode(0);
   bottom_pad->SetBorderSize(2);
   bottom_pad->SetGridx();
   bottom_pad->SetGridy();
   bottom_pad->SetTickx(1);
   bottom_pad->SetTicky(1);
   bottom_pad->SetLeftMargin(0.14);
   bottom_pad->SetRightMargin(0.05);
   bottom_pad->SetTopMargin(0);
   bottom_pad->SetBottomMargin(0.3);
   bottom_pad->SetFrameBorderMode(0);
   bottom_pad->SetFrameBorderMode(0);
   
   Double_t Graph0_fx1001[50] = {
   0,
   0,
   0,
   0,
   0.45,
   0.55,
   0.65,
   0.75,
   0.85,
   0.95,
   1.05,
   1.15,
   1.25,
   1.35,
   1.45,
   1.55,
   1.65,
   1.75,
   1.85,
   1.95,
   2.05,
   2.15,
   2.25,
   2.35,
   2.45,
   2.55,
   2.65,
   2.75,
   2.85,
   2.95,
   3.05,
   3.15,
   3.25,
   3.35,
   3.45,
   3.55,
   3.65,
   3.75,
   3.85,
   3.95,
   4.05,
   4.15,
   4.25,
   4.35,
   4.45,
   4.55,
   0,
   0,
   0,
   0};
   Double_t Graph0_fy1001[50] = {
   0,
   0,
   0,
   0,
   0.8286194,
   0.7301238,
   0.7662478,
   0.8564889,
   0.7759124,
   0.855718,
   0.8315564,
   0.8444568,
   0.8494992,
   0.9034776,
   0.9747442,
   1.02012,
   0.9379327,
   0.9173091,
   0.953834,
   1.05254,
   1.010214,
   0.9541226,
   1.041367,
   0.9586845,
   0.926789,
   1.008889,
   0.9978522,
   0.998725,
   0.9971842,
   1.036116,
   0.9711473,
   0.9585369,
   1.152986,
   1.108488,
   1.116543,
   1.252487,
   1.070115,
   1.090588,
   0.961755,
   1.198189,
   1.550271,
   2.472934,
   1.38277,
   1.351535,
   0.5601218,
   1.631024,
   0,
   0,
   0,
   0};
   Double_t Graph0_fex1001[50] = {
   0,
   0,
   0,
   0,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0.05,
   0,
   0,
   0,
   0};
   Double_t Graph0_fey1001[50] = {
   0,
   0,
   0,
   0,
   0.04732081,
   0.04427285,
   0.0505608,
   0.05703961,
   0.05610251,
   0.06014834,
   0.05919843,
   0.06034347,
   0.06240647,
   0.0643421,
   0.06654303,
   0.06983254,
   0.06010475,
   0.05789869,
   0.05858826,
   0.0565102,
   0.05008743,
   0.04417463,
   0.0436133,
   0.0377973,
   0.03493248,
   0.03476872,
   0.03371378,
   0.03283611,
   0.0323679,
   0.03295474,
   0.03163461,
   0.0350626,
   0.05720439,
   0.07469853,
   0.08737243,
   0.1150233,
   0.1250691,
   0.1582329,
   0.158536,
   0.2245611,
   0.3119823,
   0.6565635,
   0.4742516,
   0.4928817,
   0.3016915,
   0.9494441,
   0,
   0,
   0,
   0};
   TGraphErrors *gre = new TGraphErrors(50,Graph0_fx1001,Graph0_fy1001,Graph0_fex1001,Graph0_fey1001);
   gre->SetName("Graph0");
   gre->SetTitle("");
   gre->SetFillColor(1);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_Graph1001 = new TH1F("Graph_Graph1001","",100,0,5.06);
   Graph_Graph1001->SetMinimum(0.7);
   Graph_Graph1001->SetMaximum(1.35);
   Graph_Graph1001->SetDirectory(0);
   Graph_Graph1001->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1001->SetLineColor(ci);
   Graph_Graph1001->GetXaxis()->SetTitle("massVlep [GeV] ");
   Graph_Graph1001->GetXaxis()->SetRange(1,99);
   Graph_Graph1001->GetXaxis()->CenterTitle(true);
   Graph_Graph1001->GetXaxis()->SetLabelFont(42);
   Graph_Graph1001->GetXaxis()->SetLabelSize(0.12);
   Graph_Graph1001->GetXaxis()->SetTitleSize(0.15);
   Graph_Graph1001->GetXaxis()->SetTitleOffset(0.9);
   Graph_Graph1001->GetXaxis()->SetTitleFont(42);
   Graph_Graph1001->GetYaxis()->SetTitle("Data / MC ");
   Graph_Graph1001->GetYaxis()->CenterTitle(true);
   Graph_Graph1001->GetYaxis()->SetLabelFont(42);
   Graph_Graph1001->GetYaxis()->SetLabelSize(0.1);
   Graph_Graph1001->GetYaxis()->SetTitleSize(0.15);
   Graph_Graph1001->GetYaxis()->SetTitleOffset(0.22);
   Graph_Graph1001->GetYaxis()->SetTitleFont(42);
   Graph_Graph1001->GetZaxis()->SetLabelFont(42);
   Graph_Graph1001->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1001->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1001->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1001);
   
   gre->Draw("ape");
   TLine *line = new TLine(0,1,5,1);

   ci = TColor::GetColor("#ff0000");
   line->SetLineColor(ci);
   line->Draw();
   bottom_pad->Modified();
   c1->cd();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
