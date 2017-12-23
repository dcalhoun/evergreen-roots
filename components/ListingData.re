type item = {
  listing_id: int,
  price: string,
  title: string
};

module Decode = {
  let item = (json) =>
    Json.Decode.{
      listing_id: json |> field("listing_id", int),
      price: json |> field("price", string),
      title: json |> field("title", string)
    };
  let items = (json) => Json.Decode.(json |> array(item));
};

/* Why can I not desctructure? */
let fetch = (callback) =>
  Js.Promise.(
    Fetch.fetch("http://localhost:3000/api/listings")
    |> then_(Fetch.Response.json)
    |> then_(
         ({results}) =>
           results
           |> Decode.items
           |> (
             (items) => {
               callback(items);
               resolve()
             }
           )
       )
    |> ignore
  );
