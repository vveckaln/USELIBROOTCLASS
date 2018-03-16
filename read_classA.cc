#include "classA.hh"
#include "cont.hh"
#include "TFile.h"
#include "TH1F.h"
#include "TApplication.h"
int main()
{
  TFile *f = TFile::Open("testclassA.root");
  classA * c = (classA*) f -> Get("classA_");
  c -> Do();
  printf("integral %f\n", c -> _th1 -> Integral());
  f -> Close();
}
