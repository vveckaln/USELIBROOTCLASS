#include "classA.hh"
#include "TFile.h"
#include "TH1F.h"
#include "TApplication.h"
int main()
{
  //TApplication app("myapp", 0, 0);
  TH1F *h = new TH1F(TString("histo_"), "histo", 5, -2, 2);
 
  h -> FillRandom("gaus", 1000);
  classA *a = new classA();
  a -> SetName(TString("classA_") );
  a -> n = 1;
  a -> _th1 = h;
  a -> Do();
  TFile *f = TFile::Open("testclassA.root", "RECREATE");
  a -> Write();
  //  app.Run(kTRUE);
  //app.Terminate();
  f -> Close();
}
