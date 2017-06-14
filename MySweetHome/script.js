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
    $('.mouvement').prop('checked', data.mouvement);
    $('.garageOuvert').prop('checked', data.garageOuvert);
  });

  // 300ms après le succès, s'appelle récursivement
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
  getInfos();
  test();
});
