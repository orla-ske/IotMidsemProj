<?php
$servername="localhost";
$username="root";
$password="";
$dbname="waterLevelDB";

$con = mysqli_connect($servername,$username,$password,$dbname);

/*$date = date("d-m-y");
$time = date('h:i:s');

if (!isset($_GET['waterLevel'])) 
    die("water level not specified");
if ($_GET['tempdataID']=='')
    die(" water level is blank");yb
if (!is_numeric($_GET['tempdataID'] ) )
    die("water Level is not numeric");

$data=array();        

$q=mysqli_query($con,"select * from tempdata where tempdataID={$_GET['tempdataID']}");    

$row=mysqli_fetch_object($q);
while ($row)
{         
    echo " {$row->tempID} {$row->temperature} {$row->groupName}";
    $row=mysqli_fetch_object($q);
} */     

$waterLevel=$_GET['waterLevel'];


$sql = "INSERT INTO waterLevelRecord (waterLevel) VALUES('{$waterLevel}')";

if(mysqli_query($con,$sql))
echo "record added successfully";
else 
echo "failed";

?>
