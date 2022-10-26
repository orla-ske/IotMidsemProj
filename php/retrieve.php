<?php
require "db.php";


if (!isset($_GET['tempdataID'])) 
    die(" tempdataID not specified");
if ($_GET['tempdataID']=='')
    die(" tempdataID is blank");yb
if (!is_numeric($_GET['tempdataID'] ) )
    die(" tempdataID is not numeric");

$data=array();        

$q=mysqli_query($con,"select * from tempdata where tempdataID={$_GET['tempdataID']}");    

$row=mysqli_fetch_object($q);
while ($row)
{         
    echo " {$row->tempID} {$row->temperature} {$row->groupName}";
    $row=mysqli_fetch_object($q);
}       




?>
