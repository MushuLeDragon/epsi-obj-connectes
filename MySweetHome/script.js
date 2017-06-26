var ip = "http://192.168.112.14/";

function fermePortail() {
  $.get(ip + "?portal=close");
}

function ouvrePortail() {
  $.get(ip + "?portal=open");
}

function getInfos() {
  $.get(ip + 'infos', function (data) {
    console.log(data);
    $('.mouvement').prop('checked', data.mouvement);
    $('.garageOuvert').prop('checked', data.garageOuvert);
  });

  // 300ms après le succès, s'appelle récursivement
  setTimeout(getInfos, 300);
}

$(function() {
  // init polling
  getInfos();
});
