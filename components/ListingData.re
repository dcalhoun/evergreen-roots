type item = {
  listing_id: int,
  price: string,
  title: string
};

module Option = {
  let unwrapUnsafely = (data) =>
    switch data {
    | Some(v) => v
    | None => raise(Invalid_argument("unwrapUnsafely called on None"))
    };
};

module Decode = {
  let item = (json) =>
    Json.Decode.{
      listing_id: json |> field("listing_id", int),
      price: json |> field("price", string),
      title: json |> field("title", string)
    };
  let items = (items) => Json.Decode.(items |> array(item));
  /* How do unwrap results key? */
  let resp = (json) => Json.Decode.(json |> field("results"));
};

let fetch = (callback) =>
  Js.Promise.(
    Fetch.fetch("http://localhost:3000/api/listings")
    |> then_(Fetch.Response.json)
    |> then_(
         (json) =>
           json
           |> Decode.resp
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
