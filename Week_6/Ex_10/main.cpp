#include "hwlib.hpp"
#include "vector.hpp"
#include "tree.hpp"

const short PI = 3.14;
const int angleUp = -90;
const int radius = 20;

int main(void) {
	// kill the watchdog
	WDT->WDT_MR = WDT_MR_WDDIS;
	
	auto scl = hwlib::target::pin_oc(hwlib::target::pins::scl);
	auto sda = hwlib::target::pin_oc(hwlib::target::pins::sda);
	auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda(scl,sda);

	auto display = hwlib::glcd_oled(i2c_bus, 0x3C);
	hwlib::wait_ms(200);
	(void)display;
   
   
	vector start = vector(display.size.x/2, display.size.y);
	tree boom(start, radius, angleUp);

	display.clear();
	
//	hwlib::cout << l.start.x << ' ' << l.start.y << "\n";
//	hwlib::cout << l.end.x << ' ' << l.end.y;
	boom.root.draw(display);
	boom.subRoot.draw(display);

	hwlib::wait_ms(100);

	
}