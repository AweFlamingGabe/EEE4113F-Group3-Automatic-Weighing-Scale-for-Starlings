

const char PAGE_MAIN[] PROGMEM = R"=====(

<!DOCTYPE html>
<html lang="en" class="js-focus-visible">

<title>ESP32 Weight System</title>

  <style>
    table {
      position: relative;
      width:100%;
      border-spacing: 0px;
    }
    tr {
      border: 1px solid white;
      font-family: "Verdana", "Arial", sans-serif;
      font-size: 20px;
    }
    th {
      height: 20px;
      padding: 3px 15px;
      background-color: #02024b; /*#343a40*/
      color: #FFFFFF !important;
      }
    td {
      height: 20px;
       padding: 3px 15px;
    }
    .tabledata {
      font-size: 24px;
      position: relative;
      padding-left: 5px;
      padding-top: 5px;
      height:   25px;
      border-radius: 5px;
      color: #FFFFFF;
      line-height: 20px;
      transition: all 200ms ease-in-out;
      background-color: #0000AA; /*#00AA00*/
    }
    .fanrpmslider {
      width: 30%;
      height: 55px;
      outline: none;
      height: 25px;
    }
    .bodytext {
      font-family: "Verdana", "Arial", sans-serif;
      font-size: 24px;
      text-align: left;
      font-weight: light;
      border-radius: 5px;
      display:inline;
      color: #000000; /*#000000*/
    }
    .navbar {
      width: 100%;
      height: 50px;
      margin: 0;
      padding: 10px 0px;
      background-color: #fced97; /*#FFF*/
      color: #02025a; /*#000000*/
      border-bottom: 5px solid #75048b; /*#293578*/
    }
    .fixed-top {
      position: fixed;
      top: 0;
      right: 0;
      left: 0;
      z-index: 1030;
    }
    .navtitle {
      float: left;
      height: 50px;
      font-family: "Verdana", "Arial", sans-serif;
      font-size: 50px;
      font-weight: bold;
      line-height: 50px;
      padding-left: 20px;
    }
   .navheading {
     position: fixed;
     left: 60%;
     height: 50px;
     font-family: "Verdana", "Arial", sans-serif;
     font-size: 20px;
     font-weight: bold;
     line-height: 20px;
     padding-right: 20px;
   }
   .navdata {
      justify-content: flex-end;
      position: fixed;
      left: 70%;
      height: 50px;
      font-family: "Verdana", "Arial", sans-serif;
      font-size: 20px;
      font-weight: bold;
      line-height: 20px;
      padding-right: 20px;
   }
    .category {
      font-family: "Verdana", "Arial", sans-serif;
      font-weight: bold;
      font-size: 32px;
      line-height: 50px;
      padding: 20px 10px 0px 10px;
      color: #02024b; /*#000000*/
    }
    .heading {
      font-family: "Verdana", "Arial", sans-serif;
      font-weight: normal;
      font-size: 28px;
      text-align: left;
    }
  
    .btn {
      background-color: #02024b; /*#444444*/
      border: none;
      color: white;
      padding: 10px 20px;
      text-align: center;
      text-decoration: none;
      display: inline-block;
      font-size: 32px;
      margin: 4px 2px;
      cursor: pointer;
    }
    .foot {
      font-family: "Verdana", "Arial", sans-serif;
      font-size: 20px;
      position: relative;
      height:   30px;
      text-align: center;   
      color: #AAAAAA;
      line-height: 20px;
    }
    .row {
      display: flex; /* Use flexbox for layout */
      justify-content: center;
    }

    .column {
      flex: 0.3; /* Grow to fill available space */
      margin-right: 10px; /* Adjust right margin for spacing between columns */
    }
    .container {
      max-width: 1800px; /* 1800px */
      margin: 0 auto;
      text-align: center;
    }
    table tr:first-child th:first-child {
      border-top-left-radius: 5px;
    }
    table tr:first-child th:last-child {
      border-top-right-radius: 5px;
    }
    table tr:last-child td:first-child {
      border-bottom-left-radius: 5px;
    }
    table tr:last-child td:last-child {
      border-bottom-right-radius: 5px;
    }
    
  </style>

  <body style="background-color: #efefef" onload="process()">
  
    <header>
      <div class="navbar fixed-top">
          <div class="container">
            <div class="navtitle">Starling Weight Monitor</div>
            <div class="navdata" id = "date">mm/dd/yyyy</div>
            <div class="navheading">DATE</div><br>
            <div class="navdata" id = "time">00:00:00</div>
            <div class="navheading">TIME</div>
            
          </div>
      </div>
    </header>
  
    <main class="container" style="margin-top:70px">
      <div class="category">Weight Readings</div>
      <div style="border-radius: 10px !important;">
      <table style="width:70%" align="center">
      <colgroup>
        <col span="1" style="background-color:rgb(230,230,230); width: 15%; color:#000000 ;">
        <col span="1" style="background-color:rgb(200,200,200); width: 15%; color:#000000 ;">
        <col span="1" style="background-color:rgb(180,180,180); width: 15%; color:#000000 ;">
      </colgroup>
      <col span="2"style="background-color:rgb(0,0,0); color:#FFFFFF">
      <col span="2"style="background-color:rgb(0,0,0); color:#FFFFFF">
      <col span="2"style="background-color:rgb(0,0,0); color:#FFFFFF">
      <tr>
        <th colspan="1"><div class="heading">Sensor</div></th>
        <th colspan="1"><div class="heading">Value</div></th>
        <th colspan="1"><div class="heading">Voltage</div></th>
      </tr>
      <tr>
        <td><div class="bodytext">Load Cell 1</div></td>
        <td><div class="tabledata" id = "b0"></div></td>
        <td><div class="tabledata" id = "v0"></div></td>
      </tr>
      <tr>
        <td><div class="bodytext">Load Cell 2</div></td>
        <td><div class="tabledata" id = "b1"></div></td>
        <td><div class="tabledata" id = "v1"></div></td>
      </tr>
      <tr>
        <td><div class="bodytext">Load Cell 3</div></td>
        <td><div class="tabledata" id="b2"></div></td>
        <td><div class="tabledata" id="v2"></div></td>
      </tr> 
      <tr>
        <td><div class="bodytext">Weight in Grams</div></td>
        <td><div class="tabledata" id = "ave"></div></td>
      </tr>
      </table>
    </div>
    <br> 
    <div class="category bodytext">Researcher Name</div>
    <br><br>
    <input class="bodytext" type="text" id="inputText" placeholder="Enter Name Here">
    <br> 
    <br>
    <div class="category bodytext">Colour Controls</div>
    <br><br>
    <div class="row">
        <div class="column">
            <span class="bodytext">Left Top:</span> 
            <select class="bodytext" type="text" name="lefttop" id="lefttop">
                <option value="" selected="selected">None</option>
            </select>
        </div>
        <div class="column">
            <span class="bodytext">Right Top:</span> 
            <select class="bodytext" name="righttop" id="righttop">
                <option value="" selected="selected">None</option>
            </select>
        </div>
    </div>
    <br>
    <div class="row">
        <div class="column">
            <span class="bodytext">Left Bottom:</span> 
            <select class="bodytext" name="leftbottom" id="leftbottom">
                <option value="" selected="selected">None</option>
            </select>
        </div>
        <div class="column">
            <span class="bodytext">Right Bottom:</span> 
            <select class="bodytext" name="rightbottom" id="rightbottom">
                <option value="" selected="selected">None</option>
            </select>
        </div>
    </div>
    <br>
    <div class="category bodytext">Miscellaneous Controls</div>
    <br><br>
    <span class="bodytext">Bird Sex:</span> 
    <select class="bodytext" type="text" name="birdsex" id="birdsex">
      <option value="" selected="selected">Select Bird Sex</option>
    </select>
    <br><br>
    <span class="bodytext">Term:</span> 
    <select class="bodytext" name="term" id="term">
      <option value="" selected="selected">Select Term</option>
    </select>
    <br><br>

    <button type="button" class="btn" id="btn_submit" onclick="sendSubmit()">APPEND DATA TO SHEET</button>

    <pre>
                                                                           
                      UUUY                                                        
           WFBFFDBBF        U                                                     
              QHQJWHOS        H                                                   
                  YLNLY BB O   J                                                  
                   H            O                                                 
                    Y           U                                                 
                    O                                                             
                    Y            N                                                
                                  H                                               
                   Q                UY                                            
                   F         YSS       J                                          
                   J      O              N                                        
                          W                N                                      
                    O     L Q                J                                    
                    U        L                 J                                  
                     J      W  Y                YJ                                
                      Y       D Q               WY H                              
                       Y         LY YJNWNOJHW HW   U J                            
                        N           UQ  NU  JLYJ  J  J L                          
                         YY             F  HF  JNYQW  Y  U                        
                           YS              YDQSBS LYL QSJ W                       
                              L                SJLULL    OU N                     
                                 JQ                QLJHJ JUWDWH                   
                                     HB     YNYY       QDBOQ QFJL                 
                                      WS    L      YQH     UF  YQUU               
                                        J                ULY   ULQ                
                                       W   S                  OQ   O              
                                     J                             H Q            
                                Y HSW  H  JH                         YJ           
                          JUSOOQ  Y  W SNQU  Q                                    
                         HONWWUFO  YS  U HJU                                      
                            NYYYYY                                                
                                 
    <pre>
    <br>
  </main>
  

  <footer div class="foot" id = "temp" >Starling Weight Monitor uinsg ESP32 by Gabriel Nichollas :D</div></footer>
  
  </body>


  <script type = "text/javascript">
  
    // global variable visible to all java functions
    var xmlHttp=createXmlHttpObject();

    var colours = ["Red", "Blue", "Yellow", "Green", "Violet", "Purple", "Magenta", "White", "Black"]
    var sexes = ["Male", "Female"]
    var terms = ["Term 1", "Term 2", "Term 3", "Term 4", "Vacation"]

    var leftTopSel = document.getElementById("lefttop");
    var leftBottomSel = document.getElementById("leftbottom");
    var rightTopSel = document.getElementById("righttop");
    var rightBottomSel = document.getElementById("rightbottom");
    var birdsex = document.getElementById("birdsex");
    var term = document.getElementById("term");

    for (var i = 0; i < colours.length; i++) {
      leftTopSel.options[leftTopSel.options.length] = new Option(colours[i], colours[i]);
      leftBottomSel.options[leftBottomSel.options.length] = new Option(colours[i], colours[i]);
      rightTopSel.options[rightTopSel.options.length] = new Option(colours[i], colours[i]);
      rightBottomSel.options[rightBottomSel.options.length] = new Option(colours[i], colours[i]);
    }
    for (var i = 0; i < sexes.length; i++) {
      birdsex.options[birdsex.options.length] = new Option(sexes[i], sexes[i]);
    }
    for (var i = 0; i < terms.length; i++) {
      term.options[term.options.length] = new Option(terms[i], terms[i]);
    }

    // function to create XML object
    function createXmlHttpObject(){
      if(window.XMLHttpRequest){
        xmlHttp=new XMLHttpRequest();
      }
      else{
        xmlHttp=new ActiveXObject("Microsoft.XMLHTTP");
      }
      return xmlHttp;
    }

    function sendSubmit() {
      var leftTopSel = document.getElementById("lefttop").value;
      var leftBottomSel = document.getElementById("leftbottom").value;
      var rightTopSel = document.getElementById("righttop").value;
      var rightBottomSel = document.getElementById("rightbottom").value;
      
      var date = document.getElementById("date").innerText;
      var time = document.getElementById("time").innerText;
      
      var birdsex = document.getElementById("birdsex").value;
      var term = document.getElementById("term").value;

      var name = document.getElementById("inputText").value;
      var mass = document.getElementById("ave").innerText;
      
      var colors = [leftTopSel, leftBottomSel, rightTopSel, rightBottomSel];
      var birdId = extractFirstLetters(colors);

      var xhttp = new XMLHttpRequest();
      xhttp.open("PUT", "UPDATE_SUBMIT?leftTop=" + leftTopSel + "&leftBottom=" + leftBottomSel + "&rightTop=" + rightTopSel + "&rightBottom=" + rightBottomSel + "&date=" + date + "&time=" + time + "&birdsex=" + birdsex + "&term=" + term + "&name=" + name + "&birdId=" + birdId + "&mass=" + mass, true);
      xhttp.send();
    }
    function extractFirstLetters(colors) {
      var result = "";
      for (var i = 0; i < colors.length; i++) {
        var color = colors[i];
        var firstLetter = color.charAt(0);
        if (color === "Black") {
          firstLetter = "N";
        } else if (color === "") {
          firstLetter = "X";
        }
        result += firstLetter;
      }
      return result;
    }

    // function to handle the response from the ESP
    function response(){
      var message;
      var barwidth;
      var currentsensor;
      var xmlResponse;
      var xmldoc;
      var dt = new Date();
      var color = "#e8e8e8";
     
      // get the xml stream
      xmlResponse=xmlHttp.responseXML;
  
      // get host date and time
      document.getElementById("time").innerHTML = dt.toLocaleTimeString();
      document.getElementById("date").innerHTML = dt.toLocaleDateString();
  
      // A0
      xmldoc = xmlResponse.getElementsByTagName("B0"); //bits for A0
      message = xmldoc[0].firstChild.nodeValue;
      
      if (message > 2048){
      color = "#aa0000";
      }
      else {
        color = "#00aa00";
      }
      
      barwidth = message / 40.95;
      document.getElementById("b0").innerHTML=message;
      document.getElementById("b0").style.width=(barwidth+"%");

      xmldoc = xmlResponse.getElementsByTagName("V0"); //volts for A0
      message = xmldoc[0].firstChild.nodeValue;
      document.getElementById("v0").innerHTML=message;
      document.getElementById("v0").style.width=(barwidth+"%");
      document.getElementById("v0").style.backgroundColor=color;

  
      // A1
      xmldoc = xmlResponse.getElementsByTagName("B1");
      message = xmldoc[0].firstChild.nodeValue;
      if (message > 2048){
      color = "#aa0000";
      }
      else {
        color = "#00aa00";
      }
      document.getElementById("b1").innerHTML=message;
      width = message / 40.95;
      document.getElementById("b1").style.width=(width+"%");
      
      xmldoc = xmlResponse.getElementsByTagName("V1");
      message = xmldoc[0].firstChild.nodeValue;
      document.getElementById("v1").innerHTML=message;
      document.getElementById("v1").style.width=(width+"%");
      document.getElementById("v1").style.backgroundColor=color;
  
      xmldoc = xmlResponse.getElementsByTagName("B2");
      message = xmldoc[0].firstChild.nodeValue;
      if (message > 2048){
      color = "#aa0000";
      }
      else {
        color = "#00aa00";
      }
      document.getElementById("b2").innerHTML=message;
      width = message / 40.95;
      document.getElementById("b2").style.width=(width+"%");
      
      xmldoc = xmlResponse.getElementsByTagName("V2");
      message = xmldoc[0].firstChild.nodeValue;
      document.getElementById("v2").innerHTML=message;
      document.getElementById("v2").style.width=(width+"%");
      document.getElementById("v2").style.backgroundColor=color;
      // Calculate the average of b0, b1, and b2
      var b0Value = parseFloat(document.getElementById("b0").innerText);
      var b1Value = parseFloat(document.getElementById("b1").innerText);
      var b2Value = parseFloat(document.getElementById("b2").innerText);
      var average = (b0Value + b1Value + b2Value) / 3;

      var aveCell = document.getElementById("ave");
      var aveInt = parseInt(average);
      aveCell.innerText = aveInt

      if (average > 2048) {
          color = "#aa0000";
      } else {
          color = "#a83e00";
      }
      // document.getElementById("ave").innerHTML = aveInt;
      width = average / 40.95;
      document.getElementById("ave").style.width = (width + "%");
      document.getElementById("ave").style.backgroundColor = color;

     }

    function process(){
     
     if(xmlHttp.readyState==0 || xmlHttp.readyState==4) {
        xmlHttp.open("PUT","xml",true);
        xmlHttp.onreadystatechange=response;
        xmlHttp.send(null);
      }       
        // you may have to play with this value, big pages need more porcessing time, and hence
        // a longer timeout
        setTimeout("process()",100);
    }
  
  
  </script>

</html>



)=====";
