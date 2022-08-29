function validateForm() {
    var x = document.forms["myForm"]["fname"].value;
    if (x == "") {
      alert("Lūdzu ievadi vārdu!");
      document.getElementById('vards').style.backgroundColor = 'rgba(255,0,0,0.7)';

      return false;
    }
      var x = document.forms["myForm"]["sname"].value;
    if (x == "") {
      document.getElementById('uzvards').style.backgroundColor = 'rgba(255,0,0,0.7)';
      alert("Lūdzu ievadi uzvārdu!");
      return false;
    }
    var x = document.forms["myForm"]["mail"].value;
    if (x == "") {
      document.getElementById('pasts').style.backgroundColor = 'rgba(255,0,0,0.7)';
      alert("Lūdzu ievadi E-pastu!");
      return false;
    }
    var x = document.forms["myForm"]["phone"].value;
    if (x == "") {
      alert("Lūdzu ievadi Telefona numuru!");
      return false;
    }var x = document.forms["myForm"]["datums"].value;
    if (x == "") {
      alert("Lūdzu ievadi datumu!");
      return false;
    }var x = document.forms["myForm"]["place"].value;
    if (x == "") {
      alert("Lūdzu ievadi pasākuma norises vietu!");
      return false;

    }

    
  }
  
  function skatSarkst() {
    var x = document.getElementById("myDIV");
    if (x.style.display === "none") {
      x.style.display = "block";
    } else {
      x.style.display = "none";
    }
  }

  function vaiTelOk(){
    var y = document.getElementById('numurs');
    var ylenght = y.value.length;
    console.log(y+"cau");
    if (ylenght !=8) {alert("Telefona numurs nav ievadīts pareizi(par īsu/pat garu)") ;
    document.getElementById('numurs').style.backgroundColor = 'rgba(255,0,0,0.7)';
  return false;
  }}

  function checkDate() {
    var selectedText = document.getElementById('datepicker').value;
    var selectedDate = new Date(selectedText);
    var now = new Date();
    if (selectedDate < now) {
     alert("Ceļosim pagātnē? Datumam ir jābūt nākotnē!");
    }
  }

  function checkForm(form)
  {
    // regular expression to match required date format
    re = /^\d{1,2}\/\d{1,2}\/\d{4}$/;

    if(form.datums.value != '' && !form.datums.value.match(re)) {
      alert("Invalid date format: " + form.datums.value);
      form.datums.focus();
      return false;
    }
  }