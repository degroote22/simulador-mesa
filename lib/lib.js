if (typeof mergeInto !== "undefined")
  mergeInto(LibraryManager.library, {
    reset: function() {
      var MAX = 12;
      for (var i = 0; i < MAX; i++) {
        for (var x = 0; x < MAX; x++) {
          var gsn = i * MAX + x;
          var element = document.getElementById("gs-" + gsn);
          element.style.backgroundColor = "#000000";
        }
      }
    },
    light: function(i, j, r, g, b) {
      var MAX = 12;
      var DELAY = 16;
      console.log("lighting", { i, j, r, g, b });
      function pauseComp(ms) {
        var curr = new Date().getTime();
        ms += curr;
        while (curr < ms) {
          curr = new Date().getTime();
        }
      }
      function pad0(s) {
        return s.length == 1 ? "0" + s : s;
      }
      var decoded = i * MAX + j;
      var element = document.getElementById("gs-" + decoded);

      var bg =
        "#" +
        pad0(r.toString(16)) +
        pad0(g.toString(16)) +
        pad0(b.toString(16));
      element.style.backgroundColor = bg;
      pauseComp(DELAY);
    },
  });
