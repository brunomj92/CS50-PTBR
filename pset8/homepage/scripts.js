// scripts.js
function toggleMenu() {
    var menu = document.getElementById("menu");
    if (menu.style.display === "block") {
        menu.style.display = "none";
    } else {
        menu.style.display = "block";
    }
}

function changeBackgroundColor(color) {
    document.body.style.backgroundColor = color;
}
