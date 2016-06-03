#include <idc.idc>

static NopCode( from, fromend)
{
  auto dbg;

  PatchByte(from,0x1f);
  dbg = MakeByte(from);

  from++;
  PatchByte(from,0x20);
  dbg = MakeByte(from);


  from++;
  PatchByte(from,0x03);
  dbg = MakeByte(from);


  from++;
  PatchByte(from,0xd5);
  dbg = MakeByte(from);

  MakeCode(fromend -3);
	
}
static PatchFlower(void)
{
  auto EA;
  auto from,fromend;
  EA = ScreenEA();
  Message("ScreenEA 0x%x.\n",EA);
  //f2 01 f0 e7
//	if(Byte(EA) == 0xf2
//	|| Byte(EA+1) == 0x01 
//	|| Byte(EA+2) == 0xf0 
//	|| Byte(EA+3) == 0xe7
//	) 
//	{
//		from = EA;
//
//		NopCode(from,0);
//	}
  NopCode(EA,0);

  Message("NopCode 0x%x 0x%x.\n",from,0);
  Message("done.\n");
}
static main(void)
{
  AddHotkey("w","PatchFlower");
}