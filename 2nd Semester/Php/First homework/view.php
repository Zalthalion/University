<!-- DO NOT CHANGE THIS FILE -->
<?php 
 //If "result_status" is not set, most likely the user has opened the
 // view.php file directly. We don't want to allow this.
 if (!isset($result))
 {
      header("Location: index.php");
 }
?>
<!DOCTYPE html>
<html lang="en">
    <head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<meta name="description" content="Currency converter">
	<meta name="author" content="">
	<title>Exchange rate calculator</title>

	<!-- Bootstrap core CSS -->
        <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css" integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous">
        <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js" integrity="sha384-JjSmVgyd0p3pXB1rRibZUAYoIIy6OrQ6VrjIEaFf/nJGzIxFDsf4x0xIM+B07jRM" crossorigin="anonymous"></script>
        <script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>
        <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js" integrity="sha384-UO2eT0CpHqdSJQ6hJty5KVphtPhzWj9WO1clHTMGa3JDZwrnQq4sF86dIHNDz0W1" crossorigin="anonymous"></script>		
    </head>

    <body>

	<div class="container">
            <div class="row">
                <div class="col">

                    <form method="GET">
		
		<h2>Please, convert</h2>
                <div class="form-group row">
                    <div class="col">
                        <input type="text" name="amount" id="amount" class="form-control" placeholder="Amount" autofocus>
                    </div>
                    <div class="col">
                        <input type="text" name="bank_fee" id="bank_fee" class="form-control" placeholder="Bank fee, %" autofocus>
                    </div>
                </div>
                <div class="form-group row">
                    <div class="col">
                        <select class="form-control" name="card_currency" placeholder="Card currency">
                            <option class="form-control" selected="selected" value="">Card currency</option>
                            <?php 
                            foreach ($currencies as $value => $name) {
                                echo '<option value="'.$value.'">' . $name . '</option>'."\r\n";
                            }
                            ?>
                        </select>
                    </div>
                    <div class="col">
                        <select class="form-control" name="trans_currency" placeholder="Transaction currency">
                            <option class="form-control" selected="selected" value="">Transaction currency</option>
                            <?php 
                            foreach ($currencies as $value => $name) {
                                echo '<option value="'.$value.'">' . $name . '</option>'."\r\n";
                            }
                            ?>
                        </select>
                    </div>
                </div>               
                <div class="form-group row">
                    <div class="col">
                        <button type="submit" class="btn btn-primary">Calculate exchange rate</button>
                    </div>
                </div>		
	    </form>
		<?php if ($result == "OK") { ?>
		<div class="alert alert-success">
		    <h3>
                        <?php echo htmlspecialchars($_GET['amount'])?> <?php echo htmlspecialchars($_GET['trans_currency'])?>
                         = 
                        <?php echo htmlspecialchars($result_message)?> <?php echo htmlspecialchars($_GET['card_currency'])?>
                    </h3>
                    <p>
                        Currencies fluctuate every day. The rate shown is effective for transactions submitted to a credit card on <?php echo htmlspecialchars($date)?>, with a bank foreign transaction fee of <?php echo htmlspecialchars($_GET['bank_fee'])?>%.
                    </p>
		</div>
		<?php } elseif ($result == "ERROR") {?>
		<div class="alert alert-warning">
		    <h3>Problem detected!</h3>
                    <p><?php echo htmlspecialchars($result_message)?></p>
		</div>
		<?php } ?>
		
                    
                </div>
            </div>
        </div> <!-- /container -->

    </body>
</html>
