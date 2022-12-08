function calculate() {
  const currencyOne = document.getElementById('currencyOne').value;
  const currencyTwo = document.getElementById('currencyTwo').value;
  const amountOne = document.getElementById('amountOne').value;
  const amountTwo = document.getElementById('amountTwo');

  fetch(`https://v6.exchangerate-api.com/v6/459eeeed6880b99c09731812/latest/${currencyOne}`)
    .then((res) => res.json())
    .then((data) => {
      const rate = data.conversion_rates[currencyTwo];
      amountTwo.value = (amountOne * rate).toFixed(2);
    });
}

// Event Listeners
currencyOne.addEventListener('change', calculate);
amountOne.addEventListener('input', calculate);
currencyTwo.addEventListener('change', calculate);
amountTwo.addEventListener('input', calculate);
calculate();
