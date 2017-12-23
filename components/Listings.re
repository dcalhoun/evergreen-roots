let str = ReasonReact.stringToElement;

type items = array(ListingData.item);

let component = ReasonReact.statelessComponent("Listings");

let make = (~items: items, _children) => {
  ...component,
  render: (_self) =>
    ReasonReact.arrayToElement(
      Array.map(
        (item: ListingData.item) =>
          <Listing key=(string_of_int(item.listing_id)) item />,
        items
      )
    )
};
