#include "classB.hh"
#include "TFile.h"
#include "TH1F.h"
#include "TApplication.h"
int main()
{
  //TApplication app("myapp", 0, 0);
  double * d = new double(5);;
  classB *a = new classB();
  a -> SetName(TString("classB_") );
  a -> n = 1;
  a -> p = d;
  a -> Do();
  TFile *f = TFile::Open("testclassB.root", "RECREATE");
  f -> cd();
  a -> Write();
  //  app.Run(kTRUE);
  //app.Terminate();
  f -> Close();
}
