let str = ReasonReact.stringToElement;

type items = list(Listing.item);

let component = ReasonReact.statelessComponent("Listings");

let make = (~items: items, _children) => {
  ...component,
  render: (_self) =>
    ReasonReact.arrayToElement(
      Array.of_list(
        List.map(
          (item: Listing.item) =>
            <Listing key=(string_of_int(item.listing_id)) item />,
          items
        )
      )
    )
};
