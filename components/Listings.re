let str = ReasonReact.stringToElement;

/* type item = {
     key: string,
     listing_id: int,
     price: int,
     title: string
   };

   type items = list(item); */
let component = ReasonReact.statelessComponent("Listings");

let make = (~items, _children) => {
  ...component,
  render: (_self) =>
    ReasonReact.arrayToElement(
      Array.of_list(
        List.map(
          (item) => <Listing key=(string_of_int(item.listing_id)) item />,
          items
        )
      )
    )
};
