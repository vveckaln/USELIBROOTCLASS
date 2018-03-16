#include "classB.hh"
#include "cont.hh"
#include "TFile.h"
#include "TH1F.h"
#include "TApplication.h"
int main()
{
  TFile *f = TFile::Open("testclassB.root");
  classB * c = (classB*) f -> Get("classB_");
  c -> Do();
  printf("*p%f\n", *c -> p);
  f -> Close();
}
