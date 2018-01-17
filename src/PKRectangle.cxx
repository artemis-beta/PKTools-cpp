//Joel C. Swallow 2.8.16////////////////////////////////////////////////////////////////////////////
//This Class takes inputs for the size of a rectangle and prints a drawing of it to the terminal////
//For a rectange to be drawn both inputs must be integers of less than 100//////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <cmath>
#include "PKRectangle.hxx"
#include <string>

PKRectangle::PKRectangle(double par1, double par2){	//constructor

Calculate(par1,par2);

}

//PKRectange::PKRectangle~{}	//destructor

void PKRectangle::Calculate(double par1, double par2){

		sides[0]=par1;
		sides[1]=par2;
		sides[2]=par1;
		sides[3]=par2;

		angles[0]=90;
		angles[1]=90;

	Print();

if(par1==floor(par1) && par2==floor(par2)){	//CHECKS INPUTS ARE INTEGERS
	if(par1<=100 && par2 <=100){// && int S1==par1 && int S2==par2 && int S3==par1 && int S4==par2 ){
	//Draw rectangle to command line

	std::string Line=" - ";
	std::string Corner="+";
	std::string VertEnd="|";
	std::string Space="   ";

	//Top Side.......................................
	std::string TopSide=Corner;
	for (int i=0; i<par1; i++){
		TopSide=TopSide+Line;
	}
	TopSide=TopSide+Corner;
	//draw top line (side[0])
	std::cout<<TopSide<<std::endl;
	
	//vertical sides (side [1] & side[3])............
		//build vertical sides string
	std::string VertSides=VertEnd;
	for(int i=0; i<par1; i++){
		VertSides=VertSides+Space;
	}
	VertSides=VertSides+VertEnd;
		//print vertical sides
	for(int i=0; i<par2; i++){
		std::cout<<VertSides<<std::endl;
	}

	//Bottom Side...................................
	std::string BotSide=TopSide;	//These are the same!
	std::cout<<BotSide<<std::endl;	//print

	}
}


}

void PKRectangle::Print(){

std::cout<<"Angles="<<angles[0]<<","<<angles[1]<<std::endl;

std::cout<<"Sides="<<sides[0]<<","<<sides[1]<<","<<sides[2]<<","<<sides[3]<<std::endl;

//if(p1=<10 && p2 <=10){
        //Draw rectangle to command line

//char Line="-"

//string TopSide=Line*sides[0];

//draw top line (side[0])
//std::cout<<"*"<<TopSide<<"*"<<std::endl;

//}

}

double* PKRectangle::GetAngles(){return angles;}
double* PKRectangle::GetSides(){return sides;}
