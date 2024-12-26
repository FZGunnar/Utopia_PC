class BaseCameraHelper
{
    static int GetUniqueId(ItemBase item)
    {
        int id1, id2, id3, id4;
        item.GetPersistentID(id1, id2, id3, id4);

        return id1 + id2 + id3 + id4;
    }
}