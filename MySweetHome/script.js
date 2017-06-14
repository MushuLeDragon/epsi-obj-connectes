var ip = "http://192.168.0.23/";

function fermePortail() {
  $.get(ip + "?portal=close");
}

function ouvrePortail() {
  $.get(ip + "?portal=open");
}

function getInfos() {
  $.get(ip + 'getInfos', function (data) {
    console.log(data);
  });

  setTimeout(getInfos, 300);
}

var checked = true;

function test() {
  checked = !checked;
  $('.mouvement').prop('checked', checked);
  $('.garageOuvert').prop('checked', !checked);
  setTimeout(test, 1500);
}

$(function() {
  // init polling
  // setTimeout(getInfos, 300);
  test();
});
