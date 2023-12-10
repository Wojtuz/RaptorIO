Node (signer) czyta dostarczane na topic RaptorIN wiadomości, podpisuje je, dodaje timestamp'a i odsyła na topic RaptorOUT.

Testowałem go manualnie publikując na RaptorIN z poziomu terminala.
// rostopic pub /RaptorIN std_msgs/String "data: 'Dowolny tekst'"

Sprawdzałem czy działa odbserwując w osobnym terminalu czy input jest odpowiednio przetwarzany i wysyłany na RaptorOUT.
// rostopic echo /RaptorOUT