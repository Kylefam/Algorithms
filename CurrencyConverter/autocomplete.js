array = ["AUD","EUR","JPY","CHF","USD","AFN","ALL","DZD","AOA","ARS","AMD","AWG","AUD","ATS","BEF","AZN","BSD","BHD","BDT","BBD","BYR","BZD","BMD","BTN","BOB","BAM","BWP","BRL","GBP","BND","BGN","BIF","XOF","XAF","XPF","KHR","CAD","CVE","KYD","CLP","CNY","COP","KMF","CDF","CRC","HRK","CUC","CUP","CYP","CZK","DKK","DJF","DOP","XCD","EGP","SVC","EEK","ETB","EUR","FKP","FIM","FJD","GMD","GEL","DMK","GHS","GIP","GRD","GTQ","GNF","GYD","HTG","HNL","HKD","HUF","ISK","INR","IDR","IRR","IQD","IED","ILS","ITL","JMD","JPY","JOD","KZT","KES","KWD","KGS","LAK","LVL","LBP","LSL","LRD","LYD","LTL","LUF","MOP","MKD","MGA","MWK","MYR","MVR","MTL","MRO","MUR","MXN","MDL","MNT","MAD","MZN","MMK","ANG","NAD","NPR","NLG","NZD","NIO","NGN","KPW","NOK","OMR","PKR","PAB","PGK","PYG","PEN","PHP","PLN","PTE","QAR","RON","RUB","RWF","WST","STD","SAR","RSD","SCR","SLL","SGD","SKK","SIT","SBD","SOS","ZAR","KRW","ESP","LKR","SHP","SDG","SRD","SZL","SEK","CHF","SYP","TWD","TZS","THB","TOP","TTD","TND","TRY","TMM","USD","UGX","UAH","UYU","AED","VUV","VEB","VND","YER","ZMK","ZWD"];

function autocomplete(input) {
    let currentFocus;
  
    input.addEventListener("input", function(e) {
      let x, y, i, value = this.value;
      closeallLists();
      if (!value) return false;
      currentFocus = -1;
      x = document.createElement("DIV");
      x.setAttribute("id", this.id + "autocomplete-list");
      x.setAttribute("class", "autocomplete-items");
      this.parentNode.appendChild(x);
  
      for (i = 0; i < array.length; i++) {
        if (array[i].substr(0, value.length).toUpperCase() === value.toUpperCase()) {
          y = document.createElement("DIV");
          y.innerHTML = "<strong>" + array[i].substr(0, value.length) + "</strong>";
          y.innerHTML += array[i].substr(value.length);
          y.innerHTML += "<input type='hidden' value='" + array[i] + "'>";
          y.addEventListener("click", function(e) {
            input.value = this.getElementsByTagName("input")[0].value;
            closeallLists();
          });
          x.appendChild(y);
        }
      }
    });
  
    input.addEventListener("keydown", function(e) {
      let x = document.getElementById(this.id + "autocomplete-list");
      if (x) x = x.getElementsByTagName("div");
      if (e.keyCode === 40) {
        currentFocus++;
        addActive(x);
      } else if (e.keyCode === 38) {
        currentFocus--;
        addActive(x);
      } else if (e.keyCode === 13) {
        e.preventDefault();
        if (currentFocus > -1) {
          if (x) x[currentFocus].click();
        }
      }
    });
  
    function addActive(x) {
      if (!x) return false;
      removeActive(x);
      if (currentFocus >= x.length) currentFocus = 0;
      if (currentFocus < 0) currentFocus = x.length - 1;
      x[currentFocus].classList.add("autocomplete-active");
    }
    function removeActive(x) {
        for (var i = 0; i < x.length; i++) {
            x[i].classList.remove("autocomplete-active");
        }
    }
    function closeallLists(elmnt) {
        var x = document.getElementsByClassName("autocomplete-items");
        for (var i = 0; i < x.length; i++) {
            if (elmnt != x[i] && elmnt != input) {
                x[i].parentNode.removeChild(x[i]);
            }
        }
    }
    document.addEventListener("click", function (e) {
        closeallLists(e.target);
    });
}

autocomplete(document.getElementById("currencyOne"));
autocomplete(document.getElementById("currencyTwo"));