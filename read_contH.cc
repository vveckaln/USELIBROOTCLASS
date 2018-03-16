#include "classA.hh"
#include "cont.hh"
#include "TFile.h"
#include "TH1F.h"
#include "TApplication.h"
int main()
{
  TFile *f = TFile::Open("test.root");
  cont * c = (cont*) f -> Get("cc");
  c -> Do();
  f -> Close();
}
