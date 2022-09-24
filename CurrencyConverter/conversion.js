function calculate() {
    currencyOne = document.getElementById('currencyOne').value;
    currencyTwo = document.getElementById('currencyTwo').value;
    amountOne = document.getElementById('amountOne');
    amountTwo = document.getElementById('amountTwo');

  fetch(`https://v6.exchangerate-api.com/v6/b71ba5a6f69833fe3ac900ec/latest/${currencyOne}`)
    .then((res) => res.json())
    .then((data) => {
      rate = data.conversion_rates[currencyTwo];
      amountTwo.value = (amountOne.value * rate).toFixed(2);
    });
}

// Event Listeners
currencyOne.addEventListener('change', calculate);
amountOne.addEventListener('input', calculate);
currencyTwo.addEventListener('change', calculate);
amountTwo.addEventListener('input', calculate);
calculate();