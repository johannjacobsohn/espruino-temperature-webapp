var ow = new OneWire(A5);
var sensor = require("DS18B20").connect(ow);

E.on('init', function() {
	Serial2.setConsole();
});
USB.on('data', function (data) {
	USB.write(sensor.getTemp() + "\n");
});

save();
