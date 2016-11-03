#ifndef RELAY_H
#define RELAY_H

class Relay

{

public:
	
	Relay(int pinNumber);
	
	bool GetState();
	bool setState(bool on);

	
private:

	bool _on;
};


#endif
