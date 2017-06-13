function ouvrePortail() {
  $.post("ouvrePortail", { ouvre: true }, function(data) {
    console.log(data);
  });
}

function fermePortail() {
  $.post("ouvrePortail", { ouvre: false }, function(data) {
    console.log(data);
  });
}

function isGarageOuvert() {
  $.get("isGarageOuvert", function(data) {
    $(".isGarageOuvert").html(data);
  });
}

function isMovement() {
  $.get("isMovement", function(data) {
    $(".isMovement").html(data);
  });
}

$(function() {
  // init polling
  setTimeout(isGarageOuvert, 300);
  setTimeout(isMovement, 300);
});
