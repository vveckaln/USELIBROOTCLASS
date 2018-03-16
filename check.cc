#include "classA.hh"
#include "cont.hh"
#include "TFile.h"
#include "TH1F.h"
#include "TApplication.h"
int main()
{
  //TApplication app("myapp", 0, 0);
  cont c;
  for (unsigned short ind = 0 ; ind < 5; ind ++)
    {
      TH1F *h = new TH1F(TString("histo_") + (unsigned long) ind, "histo", 5, -2, 2);
      h -> FillRandom("gaus", 1000*(ind +1));
      classA *a = new classA();
      a -> SetName(TString("classA_") + (unsigned long) ind);
      a -> _th1 = h;
      c.v.push_back(a);
    }
  c.SetName("cc");
  c.Do();
  TFile *f = TFile::Open("test.root", "RECREATE");
  c.Write();
  //  app.Run(kTRUE);
  //app.Terminate();
  f -> Close();
}
