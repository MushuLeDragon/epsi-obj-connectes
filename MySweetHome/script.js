var ip = "http://192.168.0.23/";

// function ouvrePortail() {
//   $.post("ouvrePortail", { ouvre: true }, function(data) {
//     console.log(data);
//   });
// }
//
// function fermePortail() {
//   $.post("ouvrePortail", { ouvre: false }, function(data) {
//     console.log(data);
//   });
// }

function fermePortail() {
  console.log("ça devrait close");
  $.get(ip + "?portal=close");
}

function ouvrePortail() {
  console.log("ça devrait oepn");
  $.get(ip + "?portal=open");
}
//
// function isGarageOuvert() {
//   $.get("isGarageOuvert", function(data) {
//     $(".isGarageOuvert").html(data);
//   });
// }
//
// function isMovement() {
//   $.get("isMovement", function(data) {
//     $(".isMovement").html(data);
//   });
// }

$(function() {
  // init polling
  // setTimeout(isGarageOuvert, 300);
  // setTimeout(isMovement, 300);
  // $.ajax({
  //   url: ip + "?portal=close",
  // });
  // function ()
  // $.get(ip + "?portal=open", function(data) {
  //   console.log(data);
  // });
});
