<?php
require "db.php";

$sql = "select * from waterLevel";
$result = mysqli_query($con,$sql);
$row=mysqli_fetch_object($sql);
if($row){
  while($row=$result->fetch_assoc()){
    echo "<tr><td>".$row["ID"]."</td><td>".$row["Date"]."</td></tr>"."</td><td>".$row["tankID"]."</td></tr>"."</td><td>".$row["waterLevel"]."</td></tr>";
  }
  echo "</table>";
}
else{
  echo "Table Empty";
}


?>