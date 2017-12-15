#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void calculations(int net_gain[72], int total_win_loss[72], fstream& file, int pos){
        int num;
	file >> num;
	if(num >= 100){
		total_win_loss[pos] += 1;
	}
	net_gain[pos] += (num - 100);
}

int main(){

	
	int net_gain[72] = {0};
	int total_win_loss[72] = {0};
	int trials;
	cout << "ENTER NUMBER OF TRIALS" << endl;
	cin >> trials;
	
	fstream file00;
	file00.open("alternate1324.txt");
	fstream file01;
	file01.open("alternateBET10.txt");
	fstream file02;
	file02.open("alternateBET25.txt");
	fstream file03;
	file03.open("alternateCOUNTBET.txt");
	fstream file04;
	file04.open("alternateDALEMBERT.txt");
	fstream file05;
	file05.open("alternateDOUBLEUP.txt");
	fstream file06;
	file06.open("alternateFIBONNACCI.txt");
	fstream file07;
	file07.open("alternatePAROLI.txt");

	
	
	fstream file08;
	file08.open("alwaysbanker1324.txt");
	fstream file09;
	file09.open("alwaysbankerBET10.txt");
	fstream file10;
	file10.open("alwaysbankerBET25.txt");
	fstream file11;
	file11.open("alwaysbankerCOUNTBET.txt");
	fstream file12;
	file12.open("alwaysbankerDALEMBERT.txt");
	fstream file13;
	file13.open("alwaysbankerDOUBLEUP.txt");
	fstream file14;
	file14.open("alwaysbankerFIBONNACCI.txt");
	fstream file15;
	file15.open("alwaysbankerPAROLI.txt");

	fstream file16;
	file16.open("alwaysplayer1324.txt");
	fstream file17;
	file17.open("alwaysplayerBET10.txt");
	fstream file18;
	file18.open("alwaysplayerBET25.txt");
	fstream file19;
	file19.open("alwaysplayerCOUNTBET.txt");
	fstream file20;
	file20.open("alwaysplayerDALEMBERT.txt");
	fstream file21;
	file21.open("alwaysplayerDOUBLEUP.txt");
	fstream file22;
	file22.open("alwaysplayerFIBONNACCI.txt");
	fstream file23;
	file23.open("alwaysplayerPAROLI.txt");

	fstream file24;
	file24.open("copylastwin1324.txt");
	fstream file25;
	file25.open("copylastwinBET10.txt");
	fstream file26;
	file26.open("copylastwinBET25.txt");
	fstream file27;
	file27.open("copylastwinCOUNTBET.txt");
	fstream file28;
	file28.open("copylastwinDALEMBERT.txt");
	fstream file29;
	file29.open("copylastwinDOUBLEUP.txt");
	fstream file30;
	file30.open("copylastwinFIBONNACCI.txt");
	fstream file31;
	file31.open("copylastwinPAROLI.txt");

	fstream file32;
	file32.open("countbanker1324.txt");
	fstream file33;
	file33.open("countbankerBET10.txt");
	fstream file34;
	file34.open("countbankerBET25.txt");
	fstream file35;
	file35.open("countbankerCOUNTBET.txt");
	fstream file36;
	file36.open("countbankerDALEMBERT.txt");
	fstream file37;
	file37.open("countbankerDOUBLEUP.txt");
	fstream file38;
	file38.open("countbankerFIBONNACCI.txt");
	fstream file39;
	file39.open("countbankerPAROLI.txt");

	fstream file40;
	file40.open("countplayer1324.txt");
	fstream file41;
	file41.open("countplayerBET10.txt");
	fstream file42;
	file42.open("countplayerBET25.txt");
	fstream file43;
	file43.open("countplayerCOUNTBET.txt");
	fstream file44;
	file44.open("countplyerDALEMBERT.txt");
	fstream file45;
	file45.open("countplayerDOUBLEUP.txt");
	fstream file46;
	file46.open("countplayerFIBONNACCI.txt");
	fstream file47;
	file47.open("countplayerPAROLI.txt");

	fstream file48;
	file48.open("countbankerhigh1324.txt");
	fstream file49;
	file49.open("countbankerhighBET10.txt");
	fstream file50;
	file50.open("countbankerhighBET25.txt");
	fstream file51;
	file51.open("countbankerhighCOUNTBET.txt");
	fstream file52;
	file52.open("countbankerhighDALEMBERT.txt");
	fstream file53;
	file53.open("countbankerhighDOUBLEUP.txt");
	fstream file54;
	file54.open("countbankerhighFIBONNACCI.txt");
	fstream file55;
	file55.open("countbankerhighPAROLI.txt");

	fstream file56;
	file56.open("countplayerhigh1324.txt");
	fstream file57;
	file57.open("countplayerhighBET10.txt");
	fstream file58;
	file58.open("countplayerhighBET25.txt");
	fstream file59;
	file59.open("countplayerhighCOUNTBET.txt");
	fstream file60;
	file60.open("countplayerhighDALEMBERT.txt");
	fstream file61;
	file61.open("countplayerhighDOUBLEUP.txt");
	fstream file62;
	file62.open("countplayerhighFIBONNACCI.txt");
	fstream file63;
	file63.open("countplayerhighPAROLI.txt");

	fstream file64;
	file64.open("goagainstlast1324.txt");
	fstream file65;
	file65.open("goagainstlastBET10.txt");
	fstream file66;
	file66.open("goagainstlastBET25.txt");
	fstream file67;//ore ‘fstr
	file67.open("goagainstlastCOUNTBET.txt");
	fstream file68;
	file68.open("goagainstlastDALEMBERT.txt");
	fstream file69;
	file69.open("goagainstlastDOUBLEUP.txt");
	fstream file70;
	file70.open("goagainstlastFIBONNACCI.txt");
	fstream file71;
	file71.open("goagainstlastPAROLI.txt");

	for(int start = 0; start < trials; start++){
	int pos = 0;
	calculations(net_gain, total_win_loss, file00, pos);
	pos++;
	calculations(net_gain, total_win_loss, file01, pos);
	pos++;
	calculations(net_gain, total_win_loss, file02, pos);
	pos++;
	calculations(net_gain, total_win_loss, file03, pos);
	pos++;
	calculations(net_gain, total_win_loss, file04, pos);
	pos++;
	calculations(net_gain, total_win_loss, file05, pos);
	pos++;
	calculations(net_gain, total_win_loss, file06, pos);
	pos++;
	calculations(net_gain, total_win_loss, file07, pos);
	pos++;
	calculations(net_gain, total_win_loss, file08, pos);
	pos++;
	calculations(net_gain, total_win_loss, file09, pos);
	pos++;
	calculations(net_gain, total_win_loss, file10, pos);
	pos++;
	calculations(net_gain, total_win_loss, file11, pos);
	pos++;
	calculations(net_gain, total_win_loss, file12, pos);
	pos++;
	calculations(net_gain, total_win_loss, file13, pos);
	pos++;
	calculations(net_gain, total_win_loss, file14, pos);
	pos++;
	calculations(net_gain, total_win_loss, file15, pos);
	pos++;
	calculations(net_gain, total_win_loss, file16, pos);
	pos++;
	calculations(net_gain, total_win_loss, file17, pos);
	pos++;
	calculations(net_gain, total_win_loss, file18, pos);
	pos++;
	calculations(net_gain, total_win_loss, file19, pos);
	pos++;
	calculations(net_gain, total_win_loss, file20, pos);
	pos++;
	calculations(net_gain, total_win_loss, file21, pos);
	pos++;
	calculations(net_gain, total_win_loss, file22, pos);
	pos++;
	calculations(net_gain, total_win_loss, file23, pos);
	pos++;
	calculations(net_gain, total_win_loss, file24, pos);
	pos++;
	calculations(net_gain, total_win_loss, file25, pos);
	pos++;
	calculations(net_gain, total_win_loss, file26, pos);
	pos++;
	calculations(net_gain, total_win_loss, file27, pos);
	pos++;
	calculations(net_gain, total_win_loss, file28, pos);
	pos++;
	calculations(net_gain, total_win_loss, file29, pos);
	pos++;
	calculations(net_gain, total_win_loss, file30, pos);
	pos++;
	calculations(net_gain, total_win_loss, file31, pos);
	pos++;
	calculations(net_gain, total_win_loss, file32, pos);
	pos++;
	calculations(net_gain, total_win_loss, file33, pos);
	pos++;
	calculations(net_gain, total_win_loss, file34, pos);
	pos++;
	calculations(net_gain, total_win_loss, file35, pos);
	pos++;
	calculations(net_gain, total_win_loss, file36, pos);
	pos++;
	calculations(net_gain, total_win_loss, file37, pos);
	pos++;
	calculations(net_gain, total_win_loss, file38, pos);
	pos++;
	calculations(net_gain, total_win_loss, file39, pos);
	pos++;
	calculations(net_gain, total_win_loss, file40, pos);
	pos++;
	calculations(net_gain, total_win_loss, file41, pos);
	pos++;
	calculations(net_gain, total_win_loss, file42, pos);
	pos++;
	calculations(net_gain, total_win_loss, file43, pos);
	pos++;
	calculations(net_gain, total_win_loss, file44, pos);
	pos++;
	calculations(net_gain, total_win_loss, file45, pos);
	pos++;
	calculations(net_gain, total_win_loss, file46, pos);
	pos++;
	calculations(net_gain, total_win_loss, file47, pos);
	pos++;
	calculations(net_gain, total_win_loss, file48, pos);
	pos++;
	calculations(net_gain, total_win_loss, file49, pos);
	pos++;
	calculations(net_gain, total_win_loss, file50, pos);
	pos++;
	calculations(net_gain, total_win_loss, file51, pos);
	pos++;
	calculations(net_gain, total_win_loss, file52, pos);
	pos++;
	calculations(net_gain, total_win_loss, file53, pos);
	pos++;
	calculations(net_gain, total_win_loss, file54, pos);
	pos++;
	calculations(net_gain, total_win_loss, file55, pos);
	pos++;
	calculations(net_gain, total_win_loss, file56, pos);
	pos++;
	calculations(net_gain, total_win_loss, file57, pos);
	pos++;
	calculations(net_gain, total_win_loss, file58, pos);
	pos++;
	calculations(net_gain, total_win_loss, file59, pos);
	pos++;
	calculations(net_gain, total_win_loss, file60, pos);
	pos++;
	calculations(net_gain, total_win_loss, file61, pos);
	pos++;
	calculations(net_gain, total_win_loss, file62, pos);
	pos++;
	calculations(net_gain, total_win_loss, file63, pos);
	pos++;
	calculations(net_gain, total_win_loss, file64, pos);
	pos++;
	calculations(net_gain, total_win_loss, file65, pos);
	pos++;
	calculations(net_gain, total_win_loss, file66, pos);
	pos++;
	calculations(net_gain, total_win_loss, file67, pos);
	pos++;
	calculations(net_gain, total_win_loss, file68, pos);
	pos++;
	calculations(net_gain, total_win_loss, file69, pos);
	pos++;
	calculations(net_gain, total_win_loss, file70, pos);
	pos++;
	calculations(net_gain, total_win_loss, file71, pos);
	pos++;

	}
	for(int i = 0; i < 72; i++){
		if(i < 8){
			cout << "alternate" << endl;
		}
		else if((i >= 8)&&(i < 16)){
			cout << "always banker" << endl;

		}
		else if((i >= 16)&&(i < 24)){
			cout << "always player" << endl;

		}
		else if((i >= 24)&&(i < 32)){
			cout << "copy last win" << endl;
		
		}
		else if((i >= 32)&&(i < 40)){
			cout << "count banker" << endl;
		
		}
		else if((i >= 40)&&(i < 48)){
			cout << "count player" << endl;
		
		}
		else if((i >= 48)&&(i < 56)){
			cout << "count banker high" << endl;

		}
		else if((i >= 56)&&(i < 64)){
			cout << "count player high" << endl;

		}
		else{

			cout << "go against last" << endl;
		}
		cout << endl;
		if(i % 8 == 0){
			cout << "1324 W/L = " << total_win_loss[i] << " WIN% " << (float)total_win_loss[i] / trials << " NETGAIN = " << net_gain[i] << endl;
		}
		else if(i % 8 == 1){
			cout << "BET10 W/L = " << total_win_loss[i] << " WIN% " << (float)total_win_loss[i] / trials << " NETGAIN = " << net_gain[i] << endl;
		}
		else if(i % 8 == 2){
			cout << "BET25 W/L = " << total_win_loss[i] << " WIN% " << (float)total_win_loss[i] / trials << " NETGAIN = " << net_gain[i] << endl;
		}
		else if(i % 8 == 3){
			cout << "COUNTBET W/L = " << total_win_loss[i] << " WIN% " << (float)total_win_loss[i] / trials << " NETGAIN = " << net_gain[i] << endl;
		}
		else if(i % 8 == 4){
			cout << "DALEMBERT W/L = " << total_win_loss[i] << " WIN% " << (float)total_win_loss[i] / trials << " NETGAIN = " << net_gain[i] << endl;
		}
		else if(i % 8 == 5){
			cout << "DOUBLEUP W/L = " << total_win_loss[i] << " WIN% " << (float)total_win_loss[i] / trials << " NETGAIN = " << net_gain[i] << endl;
		}
		else if(i % 8 == 6){
			cout << "FIBONACCI W/L = " << total_win_loss[i] << " WIN% " << (float)total_win_loss[i] / trials << " NETGAIN = " << net_gain[i] << endl;
		}
		else if(i % 8 == 7){
			cout << "PAROLI W/L = " << total_win_loss[i] << " WIN% " << (float)total_win_loss[i] / trials << " NETGAIN = " << net_gain[i] << endl;
		}
		cout << "==================================================================================" << endl;

	}
	return 0;
}
