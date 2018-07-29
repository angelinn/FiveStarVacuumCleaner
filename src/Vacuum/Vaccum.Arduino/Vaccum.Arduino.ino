/*
 Name:		Vaccum.ino
 Created:	7/29/2018 2:23:39 PM
 Author:	betra
*/

// the setup function runs once when you press reset or power the board
void setup() {
	pinMode(4, OUTPUT);
}

// the loop function runs over and over again until power down or reset
void loop() {
	digitalWrite(4, 1);
	delay(1000);
	digitalWrite(4, 0);
}
