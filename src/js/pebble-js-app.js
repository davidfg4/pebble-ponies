Pebble.addEventListener("ready",
  function(e) {
  }
);
Pebble.addEventListener('showConfiguration',
  function(e) {
    Pebble.openURL('http://scootaloo.com/pebble_pony_config.html');
  }
);
Pebble.addEventListener('webviewclosed',
  function(e) {
    if (e.response.substr(-4) == "true") {
      Pebble.sendAppMessage({"0": 1});
    } else {
      Pebble.sendAppMessage({"0": 0});
    }
  }
);
