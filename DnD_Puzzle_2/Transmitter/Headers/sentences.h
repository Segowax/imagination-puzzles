/*
 * const.h
 *
 *  Created on: Apr 30, 2023
 *      Author: KosmicznyBandyta
 */

#include <avr/pgmspace.h>

#ifndef HEADERS_SENTENCES_H_
#define HEADERS_SENTENCES_H_

const char firstSentence[] PROGMEM
		= "┼ Ściśle tajne! Wiadomość zaszyfrowana. Rozkaz 909, Baldwin Dorjeon - Harfiarz, prowadzę sprawę w \"Cedrowym Dworku\", cel: Agomon.\r\n"
				"Porywają istoty, torturują i rytualnie zabijają! Wzywają Asmodeusza, boga diabląt, jeżeli im się to uda, to będziemy mieli kłopoty!\r\n"
				"Wysiedlili całą wioskę \"Stara Dąbrowa\" pod pretekstem ukrywania przestępców. Cała wioska posłuży jako materiał do tego makabrycznego rytuału!\r\n"
				"Staram się ustalić miejsce rytuału, niejaki Varian, mnich Selune, był na miejscu, poszukuje go Agomon.\r\n"
				"Być może wie jak tam trafić - obawiam się, że może mieć coś wspólnego z przestępcami ze \"Starej Dąbrowej\".\r\n"
				"Za tydzień od nadania tej wiadomości będę w Priapurl, musimy się tam spotkać i ustalić dalszy plan działania. ┼\r\n\r\n";
const char secondSentence[] PROGMEM
		= "┼ Szalony Kamerinie, już Ci podaję przepis na Twoją dolegliwość -> weź dwa kawałki zmierzchodrzewu i je zetrzyj na wiór,\r\n"
				"następnie zalej je dobrym krasnoludzkim piwem. Zostaw tę meszaninę na dwa/trzy dni pod oknem.\r\n"
				"Gdy odpowiedni czas nadejdzie, wypij. Twój ból głowy powinien ustąpić. ┼\r\n\r\n";
const char thridSentence[] PROGMEM
		= "┼ Wybierz odpowiedni materiał: Wybierz stal o odpowiednim składzie chemicznym i właściwościach fizycznych, która będzie odpowiednia do danego wyrobu.\r\n"
				"Przygotuj piec: Piec musi być odpowiednio przygotowany do topienia stali. Należy upewnić się, że piec jest dobrze izolowany i posiada wystarczającą ilość paliwa.\r\n"
				"Dodaj węgiel drzewny: Dodaj do pieca węgiel drzewny, który posłuży jako źródło ciepła i pomoże w rozgrzaniu stali.\r\n"
				"Dodaj surową stal: Dodaj do pieca surową stal, a następnie rozgrzej ją do odpowiedniej temperatury topnienia.\r\n"
				"Dodaj węgiel kamienny: Dodaj do pieca węgiel kamienny, który pomoże w utrzymaniu odpowiedniej temperatury topnienia.\r\n"
				"Odstaw gorącą stal: Po uzyskaniu pożądanej temperatury topnienia, wyjmij stal z pieca i odstaw ją na płaskiej powierzchni, aby się ostygła.\r\n"
				"Obróbka stali: Po ostudzeniu stali, można przystąpić do jej obróbki, np. poprzez kucie, walcowanie lub wycinanie odpowiednich kształtów. ┼\r\n\r\n";
const char forthSentence[] PROGMEM
		= "┼ Nie ważne jak, czy dobrze czy źle, zapamiętaj -> Życie to przygody lub pustka! ┼\r\n\r\n";
const char fifthSentence[] PROGMEM
		= "┼ Ulmoth smuci mnie ta wiadomość, staję się coraz bardziej rozdrażniony.\r\n"
				"Roześlij wiadomość do łowców głów z konkursem na polowanie.\r\n"
				"Varian, Nina, Kai, Yazon, Kaltar muszą zginąć, a szczególności Varian.\r\n"
				"Możesz wyznaczyć nagrodę 10 000 sztuk złota za ich śmierć.┼\r\n\r\n";
const char sixthSentence[] PROGMEM
		= "┼ Halooooo, tu Elmnister. Ktoś mnie słyszy?! Podróżując astralnie, znalazłem kamień życzeń, niestety nie mogę go podnieść :(.\r\n"
				"Podaję współrzędne 10.347, 112.324, jeżeli go znajdziesz myśl dobrze o starym Elmnisterze! ┼\r\n\r\n";

const char *sentences[7] = { firstSentence, secondSentence, thridSentence,
		forthSentence, fifthSentence, sixthSentence };

#endif /* HEADERS_SENTENCES_H_ */
