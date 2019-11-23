#define MAX_REQUEST_LEN 255

// WIFI name and password
#define SSID "SSID"
#define PASSWORD "PASSWORD"

// an array of URLs that are supposed to be called
char requests[][MAX_REQUEST_LEN] = {
    "http://192.168.178.65/control?cmd=event,toggle",
    "http://192.168.178.197/control?cmd=event,toggle"
    };