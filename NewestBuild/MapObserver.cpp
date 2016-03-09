#include "MapObserver.h"

using namespace std;

MapObserver::MapObserver() {

}

MapObserver::MapObserver(Map brazil) {
	

	map = new Fl_Group(0, 0, 885, 825, "MAP");
	map->begin();

	map->box(FL_GTK_UP_FRAME);
	map->color(FL_BLACK);
	map->labelsize(46);
	map->align(Fl_Align(FL_ALIGN_TOP | FL_ALIGN_INSIDE));

	vector<Map::City> cities = brazil.getCities();

	for (vector<Map::City>::iterator it = cities.begin(); it != cities.end(); it++) {
		string cityName = (*it).getCityName();
		const char* cN= cityName.c_str();
		int x = (*it).getX();
		int y = (*it).getY();
		string color1 = (*it).getColor();
		int color = 12;

		if (color1 == "red") color = 193;
		else if (color1 == "green") color = 62;
		else if (color1 == "blue") color = 6;
		else if (color1 == "yellow") color = 3;
		else if (color1 == "pink") color = 5;
		else if (color1 == "orange") color = 11;

		Fl_Group* city = new Fl_Group(x, y, 85, 21, cN);
		city->begin();
		city->box(FL_UP_BOX);
		city->color((Fl_Color)color);
		boavista1 = new Fl_Button(x + 10, y + 1, 20, 20, "10");
		Fl_Button* boavista2 = new Fl_Button(x + 31, y + 1, 20, 20, "15");
		Fl_Button* boavista3 = new Fl_Button(x + 51, y + 1, 20, 20, "20");
		city->end();
	}
	/*
    Fl_Group* boavista = new Fl_Group(55, 28, 85, 21, "Boa Vista");
    boavista->begin();
      	boavista->box(FL_UP_BOX);
      	boavista->color((Fl_Color)3);
      	boavista1 = new Fl_Button(65, 29, 20, 20, "10");
    	Fl_Button* boavista2 = new Fl_Button(86, 29, 20, 20, "15");
      	Fl_Button* boavista3 = new Fl_Button(106, 29, 20, 20, "20");
    boavista->end();

    Fl_Group* macapa = new Fl_Group(185, 38, 85, 21, "Macapa");
    macapa->begin();
      	macapa->box(FL_UP_BOX);
      	macapa->color((Fl_Color)3);
     	Fl_Button* macapa1 = new Fl_Button(195, 39, 20, 20, "10");
      	Fl_Button* macapa2 = new Fl_Button(216, 39, 20, 20, "15");
      	Fl_Button* macapa3 = new Fl_Button(236, 39, 20, 20, "20");
    macapa->end();
    
    Fl_Group* manaus = new Fl_Group(115, 138, 85, 22, "Manaus");
    manaus->begin();
    	manaus->box(FL_UP_BOX);
      	manaus->color((Fl_Color)3);
      	Fl_Button* manaus1 = new Fl_Button(125, 139, 20, 20, "10");
     	Fl_Button* manaus2 = new Fl_Button(146, 139, 20, 20, "15");
     	Fl_Button* manausb3 = new Fl_Button(166, 139, 20, 20, "20");
    manaus->end();

    Fl_Group* porto = new Fl_Group(115, 218, 85, 22, "Porto Velho");
    porto->begin();
      	porto->box(FL_UP_BOX);
      	porto->color((Fl_Color)3);
      	Fl_Button* porto1 = new Fl_Button(125, 219, 20, 20, "10");
      	Fl_Button* porto2 = new Fl_Button(146, 219, 20, 20, "15");
      	Fl_Button* porto3 = new Fl_Button(166, 219, 20, 20, "20");
    porto->end();

    Fl_Group* riobranco = new Fl_Group(10, 228, 85, 22, "Rio Branco");
    riobranco->begin();
      	riobranco->box(FL_UP_BOX);
      	riobranco->color((Fl_Color)3);
     	Fl_Button* riobranco1 = new Fl_Button(20, 229, 20, 20, "10");
      	Fl_Button* riobranco2 = new Fl_Button(41, 229, 20, 20, "15");
      	Fl_Button* riobranco3 = new Fl_Button(61, 229, 20, 20, "20");
    riobranco->end();

    Fl_Group* vilhena = new Fl_Group(90, 293, 85, 22, "Vilhena");
    vilhena->begin();
      	vilhena->box(FL_UP_BOX);
      	vilhena->color((Fl_Color)3);
      	Fl_Button* vilhena1 = new Fl_Button(100, 294, 20, 20, "10");
      	Fl_Button* vilhena2 = new Fl_Button(121, 294, 20, 20, "15");
      	Fl_Button* vilhena3 = new Fl_Button(141, 294, 25, 21, "20");
    vilhena->end();

    Fl_Group* cuiaba = new Fl_Group(90, 373, 85, 22, "Cuiaba");
    cuiaba->begin();
      cuiaba->box(FL_UP_BOX);
      cuiaba->color((Fl_Color)3);
      Fl_Button* cuiaba1 = new Fl_Button(100, 374, 20, 20, "10");
      Fl_Button* cuiaba2 = new Fl_Button(121, 374, 20, 20, "15");
      Fl_Button* cuiaba3 = new Fl_Button(141, 374, 20, 20, "20");
    cuiaba->end();

    Fl_Group* campo = new Fl_Group(95, 448, 85, 22, "Campo Grande");
    campo->begin();
  		campo->box(FL_UP_BOX);
		campo->color((Fl_Color)11);
		campo->labelcolor((Fl_Color)11);
		Fl_Button* campo1 = new Fl_Button(105, 449, 20, 20, "10");
		Fl_Button* campo2 = new Fl_Button(126, 449, 20, 20, "15");
		Fl_Button* campo3 = new Fl_Button(146, 449, 20, 20, "20");
    campo->end();

    Fl_Group* lonorina = new Fl_Group(110, 548, 85, 21, "Lonorina");
    lonorina->begin();
        lonorina->box(FL_UP_BOX);
        lonorina->color((Fl_Color)11);
        lonorina->labelcolor((Fl_Color)11);
        Fl_Button* lonorina1 = new Fl_Button(120, 549, 20, 20, "10");
      	Fl_Button* lonorina2 = new Fl_Button(141, 549, 20, 20, "15");
      	Fl_Button* lonorina3 = new Fl_Button(161, 549, 20, 20, "20");
    lonorina->end();

    Fl_Group* uruguaniana = new Fl_Group(65, 673, 85, 22, "Uruguaniana");
    uruguaniana->begin();
      	uruguaniana->box(FL_UP_BOX);
      	uruguaniana->color((Fl_Color)11);
      	Fl_Button* uruguaniana1 = new Fl_Button(75, 674, 20, 20, "10");
      	Fl_Button* uruguaniana2 = new Fl_Button(96, 674, 20, 20, "15");
      	Fl_Button* uruguaniana3 = new Fl_Button(116, 674, 20, 20, "20");
      uruguaniana->end();

    Fl_Group* pelotas = new Fl_Group(145, 773, 85, 22, "Pelotas");
    pelotas->begin();
      	pelotas->box(FL_UP_BOX);
      	pelotas->color((Fl_Color)11);
        Fl_Button* pelotas1 = new Fl_Button(155, 774, 20, 22, "10");
      	Fl_Button* pelotas2 = new Fl_Button(176, 774, 20, 22, "15");
     	Fl_Button* pelotas3 = new Fl_Button(196, 774, 20, 22, "20");
    pelotas->end();

    Fl_Group* portoallegre = new Fl_Group(220, 718, 85, 22, "Porto Allegre");
    portoallegre->begin();
      	portoallegre->box(FL_UP_BOX);
      	portoallegre->color((Fl_Color)11);
      	Fl_Button* portoallegre1 = new Fl_Button(230, 719, 20, 20, "10");
      	Fl_Button* portoallegre2 = new Fl_Button(251, 719, 20, 20, "15");
      	Fl_Button* portoallegre3 = new Fl_Button(271, 719, 20, 20, "20");
    portoallegre->end();

    Fl_Group* floriandopolis = new Fl_Group(330, 658, 85, 22, "Floriandopolis");
    floriandopolis->begin();
      	floriandopolis->box(FL_UP_BOX);
      	floriandopolis->color((Fl_Color)11);
      	Fl_Button* floriandopolis1 = new Fl_Button(340, 659, 20, 20, "10");
      	Fl_Button* floriandopolis2 = new Fl_Button(361, 659, 20, 20, "15");
      	Fl_Button* floriandopolis3 = new Fl_Button(381, 659, 20, 20, "20");
    floriandopolis->end();

    Fl_Group* curitiba = new Fl_Group(240, 623, 85, 22, "Curitiba");
    curitiba->begin();
      	curitiba->box(FL_UP_BOX);
      	curitiba->color((Fl_Color)11);
      	Fl_Button* curitiba1 = new Fl_Button(250, 624, 20, 20, "10");
      	Fl_Button* curitiba2 = new Fl_Button(271, 624, 20, 20, "15");
      	Fl_Button* curitiba3 = new Fl_Button(291, 624, 20, 20, "20");
    curitiba->end();

    Fl_Group* saopaulo = new Fl_Group(410, 583, 85, 22, "Sao Paulo");
    saopaulo->begin();
      saopaulo->box(FL_UP_BOX);
      saopaulo->color((Fl_Color)62);
      Fl_Button* saopaulo1 = new Fl_Button(420, 584, 20, 20, "10");
      Fl_Button* saopaulo2 = new Fl_Button(441, 584, 20, 20, "15");
      Fl_Button* saopaulo3 = new Fl_Button(461, 584, 20, 20, "20");
    saopaulo->end();

    Fl_Group* guarulhos = new Fl_Group(325, 563, 85, 22, "Guarulhos");
    guarulhos->begin();
      	guarulhos->box(FL_UP_BOX);
      	guarulhos->color((Fl_Color)62);
      	Fl_Button* guarulhos1 = new Fl_Button(335, 564, 20, 20, "10");
      	Fl_Button* guarulhos2 = new Fl_Button(356, 564, 20, 20, "15");
      	Fl_Button* guarulhos3 = new Fl_Button(376, 564, 20, 20, "20");
    guarulhos->end();

    Fl_Group* campinas = new Fl_Group(240, 543, 85, 22, "Campinas");
    campinas->begin();
     	campinas->box(FL_UP_BOX);
     	campinas->color((Fl_Color)62);
     	Fl_Button* campinas1 = new Fl_Button(250, 544, 20, 20, "10");
     	Fl_Button* campinas2 = new Fl_Button(271, 544, 20, 20, "15");
     	Fl_Button* campinas3 = new Fl_Button(291, 544, 20, 20, "20");
    campinas->end();

    Fl_Group* riodejaneiro = new Fl_Group(420, 528, 85, 22, "Rio De Janeiro");
    riodejaneiro->begin();
      	riodejaneiro->box(FL_UP_BOX);
      	riodejaneiro->color((Fl_Color)62);
      	Fl_Button* riodejaneiro1 = new Fl_Button(430, 529, 20, 20, "10");
      	Fl_Button* riodejaneiro2 = new Fl_Button(451, 529, 20, 20, "15");
      	Fl_Button* riodejaneiro3 = new Fl_Button(471, 529, 20, 20, "20");
    riodejaneiro->end();

    Fl_Group* saogoncalo = new Fl_Group(440, 488, 85, 22, "Sao Goncalo");
    saogoncalo->begin();
      	saogoncalo->box(FL_UP_BOX);
      	saogoncalo->color((Fl_Color)62);
      	Fl_Button* saogoncalo1 = new Fl_Button(450, 489, 20, 20, "10");
      	Fl_Button* saogoncalo2 = new Fl_Button(471, 489, 20, 20, "15");
      	Fl_Button* saogoncalo3 = new Fl_Button(491, 489, 20, 20, "20");
    saogoncalo->end();

    Fl_Group* vitoria = new Fl_Group(480, 418, 85, 22, "Vitoria");
    vitoria->begin();
        vitoria->box(FL_UP_BOX);
      	vitoria->color((Fl_Color)62);
      	Fl_Button* vitoria1 = new Fl_Button(490, 419, 20, 20, "10");
      	Fl_Button* vitoria2 = new Fl_Button(511, 419, 20, 20, "15");
      	Fl_Button* vitoria3 = new Fl_Button(531, 419, 20, 20, "20");
    vitoria->end();

    Fl_Group* belo = new Fl_Group(360, 428, 85, 22, "Belo Horizonte");
    belo->begin();
      	belo->box(FL_UP_BOX);
      	belo->color((Fl_Color)62);
      	Fl_Button* belo1 = new Fl_Button(370, 429, 20, 20, "10");
      	Fl_Button* belo2 = new Fl_Button(391, 429, 20, 20, "15");
      	Fl_Button* belo3 = new Fl_Button(411, 429, 20, 20, "20");
    belo->end();

    Fl_Group* uberlandia = new Fl_Group(245, 428, 85, 22, "Uberlandia");
    uberlandia->begin();
      uberlandia->box(FL_UP_BOX);
      uberlandia->color((Fl_Color)193);
      Fl_Button* uberlandia1 = new Fl_Button(255, 429, 20, 20, "10");
      Fl_Button* uberlandia2 = new Fl_Button(276, 429, 20, 20, "15");
      Fl_Button* uberlandia3 = new Fl_Button(296, 429, 20, 20, "20");
    uberlandia->end();

    Fl_Group* goiania = new Fl_Group(215, 373, 85, 22, "Goiania");
    goiania->begin();
      goiania->box(FL_UP_BOX);
      goiania->color((Fl_Color)193);
      Fl_Button* goiania1 = new Fl_Button(225, 374, 20, 20, "10");
      Fl_Button* goiania2 = new Fl_Button(246, 374, 20, 20, "15");
      Fl_Button* goiania3 = new Fl_Button(266, 374, 20, 20, "20");
    goiania->end();

    Fl_Group* porangatu = new Fl_Group(215, 293, 85, 22, "Porangatu");
    porangatu->begin();
      porangatu->box(FL_UP_BOX);
      porangatu->color((Fl_Color)193);
      Fl_Button* porangatu1 = new Fl_Button(225, 294, 20, 20, "10");
      Fl_Button* porangatu2 = new Fl_Button(246, 294, 20, 20, "15");
      Fl_Button* porangatu3 = new Fl_Button(266, 294, 20, 20, "20");
    porangatu->end();

    Fl_Group* brasilia = new Fl_Group(320, 323, 85, 22, "Brasilia");
    brasilia->begin();
      brasilia->box(FL_UP_BOX);
      brasilia->color((Fl_Color)193);
      Fl_Button* brasilia1 = new Fl_Button(330, 324, 20, 20, "10");
      Fl_Button* brasilia2 = new Fl_Button(351, 324, 20, 20, "15");
      Fl_Button* brasilia3 = new Fl_Button(371, 324, 20, 20, "20");
    brasilia->end();

    Fl_Group* montescarlos = new Fl_Group(425, 343, 85, 22, "Montes Carlos");
    montescarlos->begin();
      montescarlos->box(FL_UP_BOX);
      montescarlos->color((Fl_Color)193);
      Fl_Button* montescarlos1 = new Fl_Button(435, 344, 20, 20, "10");
      Fl_Button* montescarlos2 = new Fl_Button(456, 344, 20, 20, "15");
      Fl_Button* montescarlos3 = new Fl_Button(476, 344, 20, 20, "20");
    montescarlos->end();

    Fl_Group* salvador = new Fl_Group(550, 348, 85, 22, "Salvador Da Bahia");
    salvador->begin();
      salvador->box(FL_UP_BOX);
      salvador->color((Fl_Color)193);
      Fl_Button* salvador1 = new Fl_Button(560, 349, 20, 20, "10");
      Fl_Button* salvador2 = new Fl_Button(581, 349, 20, 20, "15");
      Fl_Button* salvador3 = new Fl_Button(601, 349, 20, 20, "20");
    salvador->end();

    Fl_Group* palmas = new Fl_Group(320, 248, 85, 22, "Palmas");
    palmas->begin();
      palmas->box(FL_UP_BOX);
      palmas->color((Fl_Color)193);
      Fl_Button* palmas1 = new Fl_Button(330, 249, 20, 20, "10");
      Fl_Button* palmas2 = new Fl_Button(351, 249, 20, 20, "15");
      Fl_Button* palmas3 = new Fl_Button(371, 249, 20, 20, "20");
    palmas->end();

    Fl_Group* petrolina = new Fl_Group(495, 253, 85, 22, "Petrolina");
    petrolina->begin();
      petrolina->box(FL_UP_BOX);
      petrolina->color((Fl_Color)6);
      Fl_Button* petrolina1 = new Fl_Button(505, 254, 20, 20, "10");
      Fl_Button* petrolina2 = new Fl_Button(526, 254, 20, 20, "15");
      Fl_Button* petrolina3 = new Fl_Button(546, 254, 20, 20, "20");
    petrolina->end();

    Fl_Group* aracaju = new Fl_Group(625, 298, 85, 22, "Aracaju");
    aracaju->begin();
      aracaju->box(FL_UP_BOX);
      aracaju->color((Fl_Color)6);
      Fl_Button* aracajub1 = new Fl_Button(635, 299, 20, 20, "10");
      Fl_Button* aracaju2 = new Fl_Button(656, 299, 20, 20, "15");
      Fl_Button* aracaju3 = new Fl_Button(676, 299, 20, 20, "20");
    aracaju->end();

    Fl_Group* macejo = new Fl_Group(655, 243, 85, 22, "Macejo");
    macejo->begin();
      macejo->box(FL_UP_BOX);
      macejo->color((Fl_Color)6);
      Fl_Button* macejo1 = new Fl_Button(665, 244, 20, 20, "10");
      Fl_Button* macejo2 = new Fl_Button(686, 244, 20, 20, "15");
      Fl_Button* macejo3 = new Fl_Button(706, 244, 20, 20, "20");
    macejo->end();

    Fl_Group* recife = new Fl_Group(690, 198, 85, 22, "Recife");
    recife->begin();
    	recife->box(FL_UP_BOX);
      	recife->color((Fl_Color)6);
      	Fl_Button* b1 = new Fl_Button(700, 199, 20, 20, "10");
      	Fl_Button* b2 = new Fl_Button(721, 199, 20, 20, "15");
      	Fl_Button* b3 = new Fl_Button(741, 199, 20, 20, "20");
    recife->end();

    Fl_Group* joaopessoa = new Fl_Group(770, 143, 85, 22, "Joao Pessoa");
    joaopessoa->begin();
      joaopessoa->box(FL_UP_BOX);
      joaopessoa->color((Fl_Color)6);
      Fl_Button* joaopessoa1 = new Fl_Button(780, 144, 20, 20, "10");
      Fl_Button* joaopessoa2 = new Fl_Button(801, 144, 20, 20, "15");
      Fl_Button* joaopessoa3 = new Fl_Button(822, 144, 20, 20, "20");
    joaopessoa->end();

    Fl_Group* natal = new Fl_Group(675, 103, 85, 22, "Natal");
    natal->begin();
      natal->box(FL_UP_BOX);
      natal->color((Fl_Color)6);
      Fl_Button* natal1 = new Fl_Button(685, 104, 20, 20, "10");
      Fl_Button* natal2 = new Fl_Button(706, 104, 20, 20, "15");
      Fl_Button* natal3 = new Fl_Button(726, 104, 20, 20, "20");
    natal->end();

    Fl_Group* fortaloza = new Fl_Group(595, 88, 85, 22, "Fortaloza");
    fortaloza->begin();
      fortaloza->box(FL_UP_BOX);
      fortaloza->color((Fl_Color)5);
      Fl_Button* fortaloza1 = new Fl_Button(605, 89, 20, 20, "10");
      Fl_Button* fortaloza2 = new Fl_Button(626, 89, 20, 20, "15");
      Fl_Button* fortaloza3 = new Fl_Button(646, 89, 20, 20, "20");
    fortaloza->end();

    Fl_Group* saoluis = new Fl_Group(415, 63, 85, 22, "Sao Luis");
    saoluis->begin();
      saoluis->box(FL_UP_BOX);
      saoluis->color((Fl_Color)5);
      Fl_Button* saoluis1 = new Fl_Button(425, 64, 20, 20, "10");
      Fl_Button* saoluis2 = new Fl_Button(446, 64, 20, 20, "15");
      Fl_Button* saoluis3 = new Fl_Button(466, 64, 20, 20, "20");
    saoluis->end();

    Fl_Group* belem = new Fl_Group(305, 48, 85, 22, "Belem");
    belem->begin();
      belem->box(FL_UP_BOX);
      belem->color((Fl_Color)5);
      Fl_Button* belem1 = new Fl_Button(315, 49, 20, 20, "10");
      Fl_Button* belem2 = new Fl_Button(336, 49, 20, 20, "15");
      Fl_Button* belem3 = new Fl_Button(356, 49, 20, 20, "20");
    belem->end();

    Fl_Group* maraba = new Fl_Group(250, 148, 85, 22, "Maraba");
    maraba->begin();
      maraba->box(FL_UP_BOX);
      maraba->color((Fl_Color)5);
      Fl_Button* maraba1 = new Fl_Button(260, 149, 20, 20, "10");
      Fl_Button* maraba2 = new Fl_Button(281, 149, 20, 20, "15");
      Fl_Button* maraba3 = new Fl_Button(301, 149, 20, 20, "20");
    maraba->end();

    Fl_Group* imperatriz = new Fl_Group(360, 148, 85, 22, "Imperatriz");
    imperatriz->begin();
      imperatriz->box(FL_UP_BOX);
      imperatriz->color((Fl_Color)5);
      Fl_Button* imperatriz1 = new Fl_Button(370, 149, 20, 20, "10");
      Fl_Button* imperatriz2 = new Fl_Button(391, 149, 20, 20, "15");
      Fl_Button* imperatriz3 = new Fl_Button(411, 149, 20, 20, "20");
    imperatriz->end();

    Fl_Group* teresina = new Fl_Group(460, 183, 85, 22, "Teresina");
    teresina->begin();
      teresina->box(FL_UP_BOX);
      teresina->color((Fl_Color)5);
      Fl_Button* teresina1 = new Fl_Button(470, 184, 20, 20, "10");
      Fl_Button* teresina2 = new Fl_Button(491, 184, 20, 20, "15");
      Fl_Button* teresina3 = new Fl_Button(511, 184, 20, 20, "20");
    teresina->end();

    Fl_Group* campina = new Fl_Group(580, 173, 85, 22, "Campina Grande");
    campina->begin();
      campina->box(FL_UP_BOX);
      campina->color((Fl_Color)6);
      Fl_Button* campina1 = new Fl_Button(590, 174, 20, 20, "10");
      Fl_Button* campina2 = new Fl_Button(611, 174, 20, 20, "15");
      Fl_Button* campina3 = new Fl_Button(631, 174, 20, 20, "20");
    campina->end();

    Fl_Group* parnaiba = new Fl_Group(505, 68, 85, 22, "Parnaiba");
    parnaiba->box(FL_UP_BOX);
      parnaiba->color((Fl_Color)5);
      Fl_Button* parnaiba1 = new Fl_Button(515, 69, 20, 20, "10");
      Fl_Button* parnaiba2 = new Fl_Button(536, 69, 20, 20, "15");
      Fl_Button* parnaiba3 = new Fl_Button(556, 69, 20, 20, "20");
    parnaiba->end();
	*/
	//boavista1->callback((Fl_Callback*)city_cb, "boavista1");
	//boavista2->callback((Fl_Callback*)city_cb);
	//boavista3->callback((Fl_Callback*)city_cb);

	buff = new Fl_Text_Buffer();
	sometext = new Fl_Text_Display(518, 385, 310, 50);
	sometext->buffer(buff);

	map->end(); // Fl_Group* map

	
}

MapObserver::~MapObserver() {

}

void MapObserver::city_cb(Fl_Widget* w, void * v) {
	((MapObserver*)(w->parent()->user_data()))->city_cb_i(w, v);
}

void MapObserver::city_cb_i(Fl_Widget* w, void * v) {
	Fl_Button* button = (Fl_Button*)w;
	const char * label = (const char *) v;
	
	displayCityInfo(label);
	

}

void MapObserver::hide() {
	map->hide();
}

void MapObserver::show() {
	map->show();
}

void MapObserver::displayCityInfo(const char * label1) {
	buff = this->buff;
	buff->text(label1);
	
}
