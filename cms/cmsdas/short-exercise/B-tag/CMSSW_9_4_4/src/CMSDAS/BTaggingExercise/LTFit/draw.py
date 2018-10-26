import ROOT

f = ROOT.TFile.Open("qcd.root","read")
hData = f.Get("h_pt100t140_pretag__DATA")
hB = f.Get("h_pt100t140_pretag__b")
hC = f.Get("h_pt100t140_pretag__c")
hL = f.Get("h_pt100t140_pretag__udsg")

hB.SetMarkerColor(ROOT.kRed)
hB.SetLineColor(ROOT.kRed)
hB.SetFillColor(ROOT.kRed)
hB.SetMarkerSize(0)

hC.SetMarkerColor(ROOT.kGreen)
hC.SetLineColor(ROOT.kGreen)
hC.SetFillColor(ROOT.kGreen)
hC.SetMarkerSize(0)

hL.SetMarkerColor(ROOT.kBlue)
hL.SetLineColor(ROOT.kBlue)
hL.SetFillColor(ROOT.kBlue)
hL.SetMarkerSize(0)

c1 = ROOT.TCanvas("c1","c1")
hMC = ROOT.THStack("MC","pretag")
hMC.Add(hL)
hMC.Add(hC)
hMC.Add(hB)
hMC.Draw("hist e1")
hData.Draw("e1 same")
hMC.SetMaximum(hData.GetMaximum()*1.2);
hMC.GetYaxis().SetTitle("Events")
hMC.GetXaxis().SetTitle("Jet Probability discriminator")
leg = ROOT.TLegend(0.6,0.6,0.8,0.8)
leg.AddEntry(hData,"Data","lp")
leg.AddEntry(hB,"b","f")
leg.AddEntry(hC,"c","f")
leg.AddEntry(hL,"udsg","f")
leg.Draw()
c1.Print("pretag.eps","")
c1.Print("pretag.png","")
