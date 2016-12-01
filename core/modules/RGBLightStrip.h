#ifndef RGB_LIGHTSTRIP_H
#define RGB_LIGHTSTRIP_H


class RGBLightStrip
{

public:
	
	RGBLightStrip();
	~RGBLightStrip();
	
	int setColor(int r, int g, int b);
	
	int getColor(int& r, int& g, int& b);
	
	int cycleRGBEffects();

private:

    int _r;
    int _g;
    int _b;

};


#endif
